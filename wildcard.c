#include <stdio.h>

int isMatch(char *str, char *pattern)
{
    int valid = 1;
    int i = 0;
    int strlen = 0;
    while (str[strlen] != '\0')
    {
        strlen++;
    }
    while (i < strlen)
    {
        if (str[i] == pattern[i] || pattern[i] == '?')
        {
            i++;
        }
        else if (pattern[i] == '*')
        {
            i = strlen;
        }
        else
        {
            i = strlen;
            valid = 0;
        }
    }
    return valid;
}
int main(void)
{
    char *str = "babanaga";
    char *str2 = "*";
    if (isMatch(str, str2))
    {
        printf("yes, the pattern works!\n");
    }
    else
    {
        printf("no, the string doesn't work :(\n");
    }
    return 0;
}