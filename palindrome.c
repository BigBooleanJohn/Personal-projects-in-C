#include <stdio.h>

#define TRUE 1

#define FALSE 0

int ispalindrome(char *string, int strlen, int cond)
{
    cond = 1;
    strlen--;
    int end = strlen;
    int begin = 0;
    while (begin < end)
    {
        if (string[begin] != string[end])
        {
            cond = 0;
        }
        begin++;
        end--;
    }
    return cond;
}

int main(void)
{

    int i = 0;
    int condition = 0;
    char arr[1000];
    printf("give me the string:");
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (ch == ' ')
        {
        }
        else
        {
            arr[i] = ch;
            i++;
        }
    }

    arr[i] = '\0';

    if (ispalindrome(arr, i, condition))
    {
        printf("yes, your string is a palindrome!\n");
    }
    else
    {
        printf("not a palindrome");
    }
    return 0;
}