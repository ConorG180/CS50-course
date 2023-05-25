#include <stdio.h>

int main(void)
{
    int height = requestHeight();
    buildPyramid(height);
}

int requestHeight(void)
{
    // Get number from user
    int number;
    printf("Pyramid height (Must be between 1 and 8)\n");
    while(1)
    {
        int result = scanf("%d", &number);
        // Clear input buffer
        while (getchar() != '\n');

        if (result == 1 && number > 0 && number <=8)
        {
            break;
        }
        else
        {
            printf("Pyramid height (Must be between 1 and 8)\n");
        }
    }
}

void buildPyramid(int number) 
{
    // Build pyramid
    for (int i = 1; i <= number; i++)
    {
        // Print spaces before each row according to height
        for (int j = 1; j <= number - i; j++)
        {
            printf(" ");
        }
        // Print first part of row
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        // Print dividing space
        printf("  ");

        // Print second part of row
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}