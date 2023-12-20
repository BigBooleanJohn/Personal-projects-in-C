#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

int process(char arr[])
{
    char ch;
    int truee = 1;
    int i = 0;
    while (truee)
    {
        ch = getchar();
        if (ch == '\n')
        {
            truee = 0;
            arr[i] = '\0';
        }
        else
        {
            arr[i] = ch;
            i++;
        }
    }
    return i;
}

void integerchecker(char arr[], int ints[], char artwo[], int n)
{
    int i;
    int j = 0;
    int k = 0;
    for (i = 0; i < n; i++)
    {
        int convertedinteger = arr[i] - '0';
        if (convertedinteger >= 0 && convertedinteger < 10)
        {
            ints[j++] = convertedinteger;
        }
        else
        {
            artwo[k++] = arr[i];
        }
    }
    printf("these are the characters you entered: %s\n", artwo);
    printf("these are the integers you put in:");
    for (i = 0; i < j; i++)
    {
        printf("%d ", ints[i]);
    }
}

int main(void)
{
    int z;
    int size = 10000;
    char str[size];
    char characters[size];
    int integers[size];
    printf("give me whatever: ");
    z = process(str);
    printf(" this is what you put in: %s\n", str);
    integerchecker(str, integers, characters, z);
    return 0;
}
