import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # Query the user's cash balance
    user_cash = db.execute(
        "SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

    # Query all the stocks the user owns from 'transactions' table
    stocks = db.execute("""
        SELECT symbol, SUM(shares) as total_shares
        FROM transactions
        WHERE user_id = ?
        GROUP BY symbol
        HAVING total_shares > 0
        """, session["user_id"])

    # For each stock, look up the current price and calculate the total value
    total_value = user_cash
    grand_total = user_cash

    for stock in stocks:
        stock_info = lookup(stock["symbol"])
        stock["name"] = stock_info["name"]
        stock["price"] = stock_info["price"]
        stock["total"] = stock["price"] * stock["total_shares"]
        total_value += stock["total"]
        grand_total += stock["total"]

    # Calculate grand total (cash + stocks' total value)
    grand_total = user_cash + total_value

    return render_template("index.html", stocks=stocks, cash=user_cash, total_value=total_value, grand_total=grand_total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy stocks."""
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")

        # Validate stock symbol
        if not symbol:
            return apology("must provide stock symbol", 400)

        stock = lookup(symbol)
        if stock is None:
            return apology("invalid stock symbol", 400)

        # Validate shares (must be a positive integer)
        try:
            shares = int(shares)
            if shares <= 0:
                return apology("must provide a positive number of shares", 400)
        except ValueError:
            return apology("shares must be a positive integer", 400)

        # Get stock price and calculate total purchase cost
        stock_price = stock["price"]
        stock_name = stock["name"]
        total_cost = stock_price * shares

        # Get the user's cash balance from the database
        user_cash = db.execute(
            "SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

        # Check if user can afford the stock
        if user_cash < total_cost:
            return apology("can't afford the shares", 400)

        # Update user's cash balance
        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?",
                   total_cost, session["user_id"])

        # Insert the purchase into the 'transactions' table
        db.execute("""
            INSERT INTO transactions (user_id, symbol, shares, price, type, timestamp)
            VALUES (?, ?, ?, ?, 'buy', CURRENT_TIMESTAMP)
            """, session["user_id"], symbol, shares, stock_price)
        
        flash(f"Bought {shares} shares of {stock_name}  successfully")

        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # Query all transactions from the 'transactions' table
    transactions = db.execute("""
        SELECT symbol, shares, price, type, timestamp
        FROM transactions
        WHERE user_id = ?
        ORDER BY timestamp DESC
        """, session["user_id"])

    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get(
                "username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")

        # Ensure a stock symbol is provided
        if not symbol:
            return apology("must provide stock symbol", 400)

        # Fetch stock data using lookup()
        stock = lookup(symbol)

        # If stock lookup fails (invalid symbol), return an apology
        if stock is None:
            return apology("invalid stock symbol", 400)

        # Render the stock details in quoted.html
        return render_template("quoted.html", stock=stock)

    else:
        # Render the form in quote.html if GET request
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        if not username:
            return apology("must provide username", 400)

        # Get the password and confirmation, validate both
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if not password or not confirmation:
            return apology("must provide password and confirmation", 400)

        if password != confirmation:
            return apology("passwords do not match", 400)

        password_hash = generate_password_hash(password)

        try:
            db.execute(
                "INSERT INTO users (username, hash) VALUES (?, ?)", username, password_hash)
        except ValueError:
            return apology("username already exists", 400)

        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        # Get symbol and shares from form
        symbol = request.form.get("symbol")
        shares_to_sell = request.form.get("shares")

        # Validate symbol and shares
        if not symbol:
            return apology("must select stock symbol", 400)

        stock = lookup(symbol)
        if stock is None:
            return apology("invalid stock symbol", 400)

        try:
            shares_to_sell = int(shares_to_sell)
            if shares_to_sell <= 0:
                return apology("must sell positive shares", 400)
        except ValueError:
            return apology("shares must be a positive integer", 400)

        # Get the number of shares the user owns
        user_shares = db.execute("""
            SELECT SUM(shares) AS total_shares
            FROM transactions
            WHERE user_id = ? AND symbol = ?
            GROUP BY symbol
            """, session["user_id"], symbol)[0]["total_shares"]

        # Ensure user has enough shares to sell
        if shares_to_sell > user_shares:
            return apology("not enough shares", 400)

        # Get the current price of the stock
        stock_price = stock["price"]
        total_sale_value = stock_price * shares_to_sell

        # Update user's cash balance
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?",
                   total_sale_value, session["user_id"])

        # Record the sale in the transactions table
        db.execute("""
            INSERT INTO transactions (user_id, symbol, shares, price, type, timestamp)
            VALUES (?, ?, ?, ?, 'sell', CURRENT_TIMESTAMP)
            """, session["user_id"], symbol, -shares_to_sell, stock_price)

        return redirect("/")

    else:
        # Display a select dropdown of the stocks the user owns
        stocks = db.execute("""
            SELECT symbol
            FROM transactions
            WHERE user_id = ?
            GROUP BY symbol
            HAVING SUM(shares) > 0
            """, session["user_id"])
        return render_template("sell.html", stocks=stocks)
