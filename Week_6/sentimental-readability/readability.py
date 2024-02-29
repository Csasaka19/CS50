def main():
    text = str(input("Text: "))
    
    letter_count = count_letters(text)
    word_count = count_words(text)
    sentence_count = count_sentences(text)
    
    S = (sentence_count / word_count) * 100
    L = (letter_count / word_count) * 100
    
    index = 0.0588 * L - 0.296 * S - 15.8
    
    grade = round(index)
    
    if grade < 1:
        print("Before Grade 1")
        return
    elif grade >= 16:
        print("Grade 16+")
        return
    else:
        print(f"Grade {grade}")
        
def count_letters(text):
    count = 0
    for char in text:
        if char.isalpha():
            count += 1
    return count

def count_words(text):
    count = 1
    for char in text:
        if char.isspace():
            count += 1
    return count

def count_sentences(text):
    count = 0
    for char in text:
        if char == "." or char == "!" or char == "?":
            count += 1
    return count

if __name__ == "__main__":
    main()