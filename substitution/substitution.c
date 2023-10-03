#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char substitute(char c, string key);
int get_position(char c);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Invalid argument!\n");
        return 1;
    }

    string key = argv[1];

    if ((strlen(key) != 26))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        plaintext[i] = substitute(plaintext[i], key);
        printf("%c", plaintext[i]);
    }
    printf("\n");
}

char substitute(char c, string key)
{
    char newchar;
    if (isalpha(c))
    {
        for (int i = 0, n = strlen(key); i < n; i++)
        {
            if (i == get_position(c))
            {
                if (islower(c))
                {
                    newchar = tolower(key[i]);
                }
                else
                {
                    newchar = toupper(key[i]);
                }
            }
        }
    }
    else
    {
        newchar = c;
    }

    return newchar;
}

int get_position(char c)
{
    int position;
    if (islower(c))
    {
        position = c - 'a';
    }
    else
    {
        position = c - 'A';
    }

    return position;
}
