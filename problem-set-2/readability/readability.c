#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int words = count_words(text);
    int letters = count_letters(text);
    int sentences = count_sentences(text);

    float av_letter = 100 * ((float) letters / words);
    float av_sentence = 100 * ((float) sentences / words);
    int result = round(0.0588 * av_letter - 0.296 * av_sentence - 15.8);

    if (result > 16)
    {
        printf("Grade 16+\n");
    }
    else if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", result);
    }
}

int count_words(string text)
{
    int num_words = 1;
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (isspace(text[i]))
        {
            num_words++;
        }
    }

    return num_words;
}


int count_letters(string text)
{
    int num_letters = 0;
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            num_letters++;
        }
    }

    return num_letters;
}

int count_sentences(string text)
{
    int num_sentences = 0;
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            num_sentences++;
        }
    }

    return num_sentences;
}
