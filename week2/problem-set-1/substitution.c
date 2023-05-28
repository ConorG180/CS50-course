#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes:
int checkArguments(short numberOfArguments);
int checkCipher(char cipher[]);
char* requestPlainText();

int main(int argc, char *argv[])
{
    if(checkArguments(argc) == 1)
    {
        return 1;
    }

    if(checkCipher(argv[1]) == 1)
    {
        return 1;
    }

    char* plainText = requestPlainText();
    
}

int checkArguments(short numberOfArguments)
{
    if (numberOfArguments > 2 || numberOfArguments < 2)
    {
        printf("Error - There should be one sole argument provided");
        return 1;
    }
    return 0;
}

int checkCipher(char cipher[])
{
    short cipherLength = strlen(cipher);
    if (cipherLength != 26)
    {
        printf("Error - String not 26 characters");
        return 1;
    }

    for (int i=0; i < cipherLength; i++)
    {
        if (cipher[i] < 65 || cipher[i] > 122)
        {
            printf("Error - String contains non-alphabetic characters");
            return 1;
        }
        for (int j = i + 1; j < cipherLength; j++)
        {
            if(cipher[i] == cipher[j])
            {
                printf("Cipher contains repeated alphabetical characters");
                return 1;
            }
        }
    }
}

char* requestPlainText()
{
    int maxLength = 501;

    char* plainText = (char*)malloc(maxLength * sizeof(char));

    if (plainText == NULL)
    {
        printf("Error - Memory allocation failed.\n");
        return NULL;
    }

    printf("plaintext: ");
    fgets(plainText, maxLength, stdin);

    if (plainText[strlen(plainText) - 1] == '\n')
    {
        plainText[strlen(plainText) - 1] = '\0';
    }

    return plainText;
}