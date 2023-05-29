#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function prototypes:
int checkArguments(short numberOfArguments);
int checkCipher(char cipher[]);
char* requestPlainText();
char* convertCipher(char* plainText, char cipher[]);

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
    char * cipheredText = convertCipher(plainText, argv[1]);
    printf("ciphertext: %s \n", cipheredText);
    
    free(plainText);
    free(cipheredText);
    return 0;
    
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


char* convertCipher(char* plainText, char cipher[])
{
    int maxLength = 501;

    char* cipheredText = (char*)malloc((maxLength + 1) * sizeof(char));

    for (int i = 0; i < strlen(plainText); i++)
    {
        if (plainText[i] >= 65 && plainText[i] <= 90)
        {
            char cipherLetter = cipher[plainText[i] - 65];
            cipheredText[i] = toupper(cipherLetter);
        }
        else if (plainText[i] >= 97 && plainText[i] <= 122)
        {
            char cipherLetter = cipher[plainText[i] - 97];
            cipheredText[i] = tolower(cipherLetter);
        }
        else
        {
            char cipherLetter = cipher[plainText[i]];
            cipheredText[i] = ' ';
        }
    }
    cipheredText[strlen(plainText)] = '\0';
    return cipheredText;
}