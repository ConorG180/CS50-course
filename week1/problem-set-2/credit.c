#include <stdio.h>

long long requestCreditCardNum(void);
short isValid(long long);
short getCardNumLength(long long);
short getFirstTwoDigits(long long cardNum);

void main(void)
{
    long long cardNum = requestCreditCardNum();
    if (isValid(cardNum) != 1)
    {
        printf("card not valid");
    }
    short firstTwoDigits = getFirstTwoDigits(cardNum);
    printf("First 2 digits: %i", firstTwoDigits);
}






short isValid(long long cardNum) {
    int sum1 = 0;
    int sum2 = 0;

    int alternate = 0;
    while(cardNum > 0) {
        if (alternate == 0) {
            // Add the last digit of num to sum1.
            sum1 = sum1 + cardNum % 10;
            alternate = 1;
        } else {
            // Multiply the last digit of num by 2, add the digits of the product to sum2.
            int doubled = 2 * (cardNum % 10);
            sum2 = sum2 + (doubled / 10) + (doubled % 10);
            alternate = 0;
        }

        // Remove the last digit from num.
        cardNum /= 10;
    }

    int totalSum = sum1 + sum2;
    printf("Sum1: %d, Sum2: %d, Total Sum: %d\n", sum1, sum2, totalSum);
    if (totalSum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


long long requestCreditCardNum(void)
{
        long long cardNum;
    while(1)
    {
        printf("Credit card Number:");
        int result = scanf("%lld", &cardNum);

        long long tempCardNum = cardNum;
        short cardNumLength = getCardNumLength(tempCardNum);
        while(getchar() != '\n');

        if (result == 1 && cardNumLength >= 13 && cardNumLength <= 16)
        {
            break;
        }
    }
    return cardNum;
}

short getCardNumLength(long long cardNum)
{
    short cardNumLength = 0;
    while (cardNum != 0)
    {
        cardNum /= 10;
        cardNumLength++;
    }
    return cardNumLength;
}

short getFirstTwoDigits(long long cardNum)
{
    printf("cardNum: %lld", cardNum);
    long long firstTwoDigits = cardNum;
    while(firstTwoDigits > 100)
    {
        firstTwoDigits /= 10;
    } 
    printf("First 2 digits: %i", firstTwoDigits);
    return (short) firstTwoDigits;
}
