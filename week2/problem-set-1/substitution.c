#include <stdio.h>
#include <string.h>

// Function prototypes:
int checkArguments(short numberOfArguments);

int main(int argc, char *argv[])
{
    if(checkArguments(argc) == 1)
    {
        return 1;
    }
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