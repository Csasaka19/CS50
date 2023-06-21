#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt user for a string
    string text = get_string("Text: ");
    // printf("%s \n", text);
    int letter_no = count_letters(text);
    // printf("%i letters\n", letter_no);
    int word_no = count_words(text);
    // printf("%i words\n", word_no);
    int sentence_no = count_sentences(text);
    // printf("%i sentences\n", sentence_no);

    // L average number of letters per 100 words in the text
    // S  average number of sentences per 100 words in the text.
    float S = (sentence_no / (float) word_no) * 100;
    float L = (letter_no / (float) word_no) * 100;
    // Coleman-Liau index.
    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_sentences(string text)
{
    int no_sentences = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            no_sentences++;
        }
    }
    return no_sentences;
}

int count_words(string text)
{
    int no_words = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isblank(text[i]))
        {
            no_words++;
        }
    }
    return no_words + 1;
}

int count_letters(string text)
{
    int no_letters = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            no_letters++;
        }
    }
    return no_letters;
}