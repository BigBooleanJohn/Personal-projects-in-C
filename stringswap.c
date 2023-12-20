#include <stdio.h>

#define TRUE 1
#define FALSE 0

int getter(char str[])
{
    char ch;
    int input_is_not_null = 1;
    int length = 0;
    while (input_is_not_null)
    {
        ch = getchar();
        str[length] = ch;
        if (ch == '\n')
        {
            input_is_not_null = FALSE;
            str[length] = '\0';
        }
        else
        {
            length++;
        }
    }
    return length;
}

void swapper(char string[], int length)
{
    int i = 0;
    int end = length - 1;
    while (i < end)
    {
        char temp = string[end];
        string[end] = string[i];
        string[i] = temp;
        i++;
        end--;
    }
}

int main(void)
{
    int size = 10000;
    char string[size];
    int length = 0;

    printf("give me a string:");
    length = getter(string);
    printf("this is the initial string: %s\n", string);
    string[length] = '\0';
    printf("length is: %d\n", length);
    swapper(string, length);
    printf("this is the swapped string: %s\n", string);
    printf("%c\n", string[length]);
}