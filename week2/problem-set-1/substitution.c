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
    // Check the number of CLI arguments. 
    // If number is not 2 (including program name), return  error
    if(checkArguments(argc) == 1)
    {
        return 1;
    }
    // Check user's cipher
    // If doesn't meet conditions (26 characters, all unique and alphabetic), return error code
    if(checkCipher(argv[1]) == 1)
    {
        return 1;
    }

    // Request user to input plain text
    char* plainText = requestPlainText();

    // Convert plain text with cipher and print result
    char * cipheredText = convertCipher(plainText, argv[1]);
    printf("ciphertext: %s \n", cipheredText);
    
    // Free memory
    free(plainText);
    free(cipheredText);
    return 0;
    
}


// Function to check num of CLI arguments
int checkArguments(short numberOfArguments)
{
    if (numberOfArguments != 2)
    {
        printf("Error - There should be one sole argument provided\n");
        return 1;
    }
    return 0;
}

// Function to check user cipher
int checkCipher(char cipher[])
{
    short cipherLength = strlen(cipher);
    if (cipherLength != 26)
    {
        printf("Error - String not 26 characters\n");
        return 1;
    }

    int characterCount[26] = {0}; // Array to count each char in cipher

    // Loop over cipher and check each character
    for (int i = 0; i < cipherLength; i++)
    {
        if (!isalpha(cipher[i]))
        {
            printf("Error - String contains non-alphabetic characters\n");
            return 1;
        }

        char lowercaseChar = tolower(cipher[i]);

        // If the char repeated in cipher, return error
        if (characterCount[lowercaseChar - 'a'] != 0)
        {
            printf("Error - Cipher contains repeated alphabetical characters\n");
            return 1;
        }

        // Count occurrence of the char in cipher
        characterCount[lowercaseChar - 'a']++;
    }

    return 0;
}

// Function to request plain text from user
char* requestPlainText()
{
    int maxLength = 501;

    // Allocate memory for plain text
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


// Function to convert into cipher text
char* convertCipher(char* plainText, char cipher[])
{
    int maxLength = 501;

    // Allocate memory for the ciphered text
    char* cipheredText = (char*)malloc((maxLength + 1) * sizeof(char));

    for (int i = 0; i < strlen(plainText); i++)
    {
        // Handle upper case letters
        if (plainText[i] >= 65 && plainText[i] <= 90)
        {
            char cipherLetter = cipher[plainText[i] - 65];
            cipheredText[i] = toupper(cipherLetter);
        }
        // Handle lower case letters
        else if (plainText[i] >= 97 && plainText[i] <= 122)
        {
            char cipherLetter = cipher[plainText[i] - 97];
            cipheredText[i] = tolower(cipherLetter);
        }
        // Handle other cases, punctuation etc.
        else
        {
            char cipherPunctuation = plainText[i];
            cipheredText[i] = plainText[i];
        }
    }
    cipheredText[strlen(plainText)] = '\0';
    return cipheredText;
}