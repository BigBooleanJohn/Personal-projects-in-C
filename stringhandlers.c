#include <stdio.h>

char *substring(int start, int end, char *arr)
{
    int i = 0;
    while (start < end)
    {
        arr[i] = arr[start];
        i++;
        start++;
    }
    arr[i] = '\0';
    printf("%s", arr);
    return arr;
}

int main(void)
{
    char *string = "daddyyy";
    substring(0, 2, string);
    return 0;
}