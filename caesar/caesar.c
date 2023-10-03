#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Invalid argument!\n");
        return 1;
    }

    if (only_digits(argv[1]) != true)
    {
        return 1;
    }

    int n = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        plaintext[i] = rotate(plaintext[i], n);
        printf("%c", plaintext[i]);
    }
    printf("\n");
}

bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    char newchar;
    if (islower(c))
    {
        newchar = 'a' + (c - 'a' + n) % 26;
    }
    else if (isupper(c))
    {
        newchar = 'A' + (c - 'A' + n) % 26;
    }
    else
    {
        newchar = c;
    }
    return newchar;
}