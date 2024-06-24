-- Keep a log of any SQL queries you execute as you solve the mystery.
-- What I know so far the theft took place on July 28, 2023 and that it took place on Humphrey Street.

-- to access the database
sqlite3 fiftyville.db

-- for the overview of the tables to review for investigation
.tables

-- To view the structures of the tables associated with the crime being investigated for a better understanding of what columns need to be looked up for this crime(Rubber Duck is missing)
.schema crime_scene_reports
.schema interviews
.schema bakery_security_logs
.schema atm_transactions
.schema phone_calls
.schema flights
.schema people
.schema airports
.schema passengers


-- To see the description of the report.
SELECT description from crime_scene_reports WHERE year = 2023 AND month = 7 AND day = 28 AND street = 'Humphrey Street';
+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                       description                                                                                                        |
+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

-- To see the interview details on the day of theft.
 SELECT name,transcript FROM interviews WHERE year = 2023 AND month = 7 AND day = 28 ;
 +---------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|  name   |                                                                                                                                                     transcript                                                                                                                                                      |
+---------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+                                                                                                                 |
| Ruth    | "Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame."                                                          |
| Eugene  | "I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money. "                                                                                                |
| Raymond | "As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket." |
+---------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

-- To view the security logs of the bakery around the time the first witness "Ruth" mentioned and suggested.
SELECT hour, minute, license_plate, activity FROM bakery_security_logs  WHERE year = 2023 AND month = 7 AND day = 28 ;
+------+--------+---------------+----------+
| hour | minute | license_plate | activity |
+------+--------+---------------+----------+
| 10   | 16     | 5P2BI95       | exit     |
| 10   | 18     | 94KL13X       | exit     |
| 10   | 18     | 6P58WS2       | exit     |
| 10   | 19     | 4328GD8       | exit     |
| 10   | 20     | G412CB7       | exit     |
| 10   | 21     | L93JTIZ       | exit     |
| 10   | 23     | 322W7JE       | exit     |
| 10   | 23     | 0NTHK55       | exit     |
| 10   | 35     | 1106N58       | exit     |
+------+--------+---------------+----------+

-- View transactions of that morning at Leggett street ATM that morning to know the thief's account or have a rough idea of it as per "Eugene"
SELECT account_number, amount , transaction_type FROM atm_transactions WHERE year=2023 AND month=7 AND day=28 AND atm_location="Leggett Street";
+----------------+--------+------------------+
| account_number | amount | transaction_type |
+----------------+--------+------------------+
| 28500762       | 48     | withdraw         |
| 28296815       | 20     | withdraw         |
| 76054385       | 60     | withdraw         |
| 49610011       | 50     | withdraw         |
| 16153065       | 80     | withdraw         |
| 86363979       | 10     | deposit          |
| 25506511       | 20     | withdraw         |
| 81061156       | 30     | withdraw         |
| 26013199       | 35     | withdraw         |
+----------------+--------+------------------+


-- Search for phone calls that are less than a minute within the day as per what Raymond had stated
SELECT caller, receiver, duration FROM phone_calls WHERE year=2023 AND month=7 AND day=28 AND duration < 60;
+----------------+----------------+----------+
|     caller     |    receiver    | duration |
+----------------+----------------+----------+
| (130) 555-0289 | (996) 555-8899 | 51       |
| (499) 555-9472 | (892) 555-8872 | 36       |
| (367) 555-5533 | (375) 555-8161 | 45       |
| (499) 555-9472 | (717) 555-1342 | 50       |
| (286) 555-6063 | (676) 555-6554 | 43       |
| (770) 555-1861 | (725) 555-3243 | 49       |
| (031) 555-6622 | (910) 555-3251 | 38       |
| (826) 555-1652 | (066) 555-9701 | 55       |
| (338) 555-6650 | (704) 555-2131 | 54       |
+----------------+----------------+----------+

-- Look for the earliets flight out of fiftyville on 29th July 2023 as claimed by Raymond
SELECT airports.full_name, flights.hour, flights.minute, flights.id FROM airports JOIN flights ON  airports.id = origin_airport_id WHERE flights.year=2023 AND flights.month=7 AND flights.day=29;
+-----------------------------+------+--------+----+
|          full_name          | hour | minute | id |
+-----------------------------+------+--------+----+
| Fiftyville Regional Airport | 16   | 0      | 18 |
| Fiftyville Regional Airport | 12   | 15     | 23 |
| Fiftyville Regional Airport | 8    | 20     | 36 |
| Fiftyville Regional Airport | 9    | 30     | 43 |
| Fiftyville Regional Airport | 15   | 20     | 53 |
+-----------------------------+------+--------+----+

-- Find the person who booked the flight tickets for 2 people. The person on the other end of the phone.
SELECT passengers.seat, passengers.passport_number FROM passengers JOIN flights ON flights.id = passengers.flight_id WHERE flights.id=36;
+------+-----------------+
| seat | passport_number |
+------+-----------------+
| 2A   | 7214083635      |
| 3B   | 1695452385      |
| 4A   | 5773159633      |
| 5C   | 1540955065      |
| 6C   | 8294398571      |
| 6D   | 1988161715      |
| 7A   | 9878712108      |
| 7B   | 8496433585      |
+------+-----------------+

-- Since the suspects are narrowed down to 8 people and the thief and his accomplice will likely seat on consective seats I will start cross checking on the consecutive seats and here is the people whose vehicles were in the bakery parking
--and made calls on the said day.
SELECT id, name, phone_number , passport_number, license_plate FROM people WHERE passport_number=1988161715;                  
449774|Taylor|(286) 555-6063|1988161715|1106N58
SELECT id, name, phone_number , passport_number, license_plate FROM people WHERE passport_number=8294398571;  
560886|Kelsey|(499) 555-9472|8294398571|0NTHK55
SELECT id, name, phone_number , passport_number, license_plate FROM people WHERE passport_number=5773159633;
686048|Bruce|(367) 555-5533|5773159633|94KL13X
SELECT id, name, phone_number , passport_number, license_plate FROM people WHERE passport_number=1695452385;
398010|Sofia|(130) 555-0289|1695452385|G412CB7

-- Search his bank account to confirm my hints since these cars were there in the bakery and a withdrawal from the ATM were made there.
SELECT bank_accounts.account_number FROM bank_accounts JOIN people ON people.id = bank_accounts.person_id WHERE people.id=449774;
76054385
SELECT bank_accounts.account_number FROM bank_accounts JOIN people ON people.id = bank_accounts.person_id WHERE people.id=560886; -- No bank account
SELECT bank_accounts.account_number FROM bank_accounts JOIN people ON people.id = bank_accounts.person_id WHERE people.id=686048;
49610011
SELECT bank_accounts.account_number FROM bank_accounts JOIN people ON people.id = bank_accounts.person_id WHERE people.id=398010; -- No bank account

-- The accomplice of Bruce and Taylor who appear everywhere 
SELECT name FROM people WHERE phone_number="(375) 555-8161";
Robin
SELECT name FROM people WHERE phone_number="(676) 555-6554";
James
-- Where they escaped to
SELECT airports.full_name, flights.hour, flights.minute, flights.id, flights.destination_airport_id FROM airports JOIN flights ON  airports.id = origin_airport_id WHERE flights.year=2023 AND flights.month=7 AND flights.day=29;