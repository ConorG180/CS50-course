int main(void)
{
    requestCreditCardNum();
}







long long requestCreditCardNum(void)
{
        long long cardNum;
    while(1)
    {
        printf("Credit card Number:");
        int result = scanf("%lld", &cardNum);

        long long tempCardNum = cardNum;
        short cardNumLength = 0;
        while (tempCardNum != 0)
        {
            tempCardNum /= 10;
            cardNumLength++;
        }
        printf("cardNum %lld cardLength %d", cardNum, cardNumLength);
        while(getchar() != '\n');

        if (result == 1 && cardNumLength >= 13 && cardNumLength <= 16)
        {
            break;
        }
    }
    printf("Exited loop");
}