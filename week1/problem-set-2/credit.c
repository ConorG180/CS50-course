#include <stdio.h>

// Function declarations
long long requestCreditCardNum(void);
short isValid(long long);
short getCardNumLength(long long);
short getFirstTwoDigits(long long cardNum);
void checkCardType(short firstTwoDigits, short cardNumLength);

int main(void)
{
    // Get card number from user
    long long cardNum = requestCreditCardNum();

    // If card is not valid, print "INVALID" and exit
    if (isValid(cardNum) != 1)
    {
        printf("INVALID");
        return 1;
    }

    // Get card number length and first two digits
    short cardNumLength = getCardNumLength(cardNum);
    short firstTwoDigits = getFirstTwoDigits(cardNum);

    // Check the card type and print accordingly
    checkCardType(firstTwoDigits, cardNumLength);
    return 1;
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

    // If the total sum ends in 0, the card is valid
    int totalSum = sum1 + sum2;
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
    // Keep asking for a number until a valid card number is entered
    while(1)
    {
        printf("Credit card Number:");
        int result = scanf("%lld", &cardNum);

        // Check if entered card number is of valid length
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
    // Count number of digits in card number
    while (cardNum != 0)
    {
        cardNum /= 10;
        cardNumLength++;
    }
    return cardNumLength;
}

short getFirstTwoDigits(long long cardNum)
{
    long long firstTwoDigits = cardNum;
    // Reduce card number until only first two digits remain
    while(firstTwoDigits > 100)
    {
        firstTwoDigits /= 10;
    } 
    return (short) firstTwoDigits;
}

void checkCardType(short firstTwoDigits, short cardNumLength)
{
    // Check for American Express
    if ((firstTwoDigits == 34 || firstTwoDigits == 37) && cardNumLength == 15)
    {
        printf("AMEX\n");
    }
    // Check for Mastercard
    else if (firstTwoDigits >= 51 && firstTwoDigits <= 55 && cardNumLength == 16)
    {
        printf("MASTERCARD\n");
    }
    // Check for Visa
    else if (firstTwoDigits / 10 == 4 && cardNumLength == 13 || cardNumLength == 16)
    {
        printf("VISA\n");
    }
    // If none of the above, print "UNKNOWN CARD BRAND"
    else
    {
        printf("UNKNOWN CARD BRAND");
    }
}