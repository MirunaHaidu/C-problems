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
    // printf("%s\n", text);

    int letters = count_letters(text);

    int words = count_words(text);

    int sentences = count_sentences(text);

    float l = (float) letters / words * 100;
    float s = (float) sentences / words * 100;

    float index = 0.0588 * l - 0.296 * s - 15.8;

    if ((int) round(index) >= 16)
    {
        printf("Grade 16+\n");
    }
    else if ((int) round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int count_letters(string text)
{
    int letters = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'z')
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentence = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }
    }
    return sentence;
}
