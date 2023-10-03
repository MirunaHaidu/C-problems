#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    bool isValid = true;

    do
    {
        card = get_long("Number: ");
    }
    while (card < 0);

    long cardCopy = card;
    long cardCopy1 = card;

    card /= 10;
    int num = 0;
    while (card != 0)
    {
        int digit = (int) (card % 10) * 2;
        num = num * 10 + digit;
        card /= 100;
    }

    int sum = 0;
    while (num != 0)
    {
        int digit = (int) (num % 10);
        sum += digit;
        num /= 10;
    }

    int sum1 = 0;
    while (cardCopy != 0)
    {
        int digit = (int) (cardCopy % 10);
        sum1 += digit;
        cardCopy /= 100;
    }

    int finalSum = sum + sum1;

    if (finalSum % 10 != 0)
    {
        isValid = false;
    }

    int length = 0;
    long reversed = 0;

    while (cardCopy1 != 0)
    {
        int digit = (int) (cardCopy1 % 10);
        reversed = reversed * 10 + digit;
        cardCopy1 /= 10;
        length++;
    }

    if (isValid)
    {
        if ((reversed % 100 == 43 || reversed % 100 == 73) && (length == 15))
        {
            printf("AMEX\n");
        }
        else if ((reversed % 100 >= 15 && reversed % 100 <= 55) && (length == 16))
        {
            printf("MASTERCARD\n");
        }
        else if ((reversed % 10 == 4) && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
