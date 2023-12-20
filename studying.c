#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printArr(char *str)
{
    if (*str == '\0')
    {
        prinf("\n done printing \n");
    }
    else
    {
        printf("%c", str);
        printArr(str + 1);
    }
}

int main(int argc, char *argv[])
{
    char *str = "lamelo ball biggg";
    printArr(str);
    return 0;
}