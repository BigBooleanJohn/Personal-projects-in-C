#include <stdio.h>
#include <stdlib.h>

/*int binarysearch(int top, int bottom, int array[], int target)
{
    if (array[top - ((top - bottom) / 2)] == target)
    {
        return top - ((top - bottom) / 2);
    }
    if (array[top - ((top - bottom) / 2)] > target)
    {
        binarysearch(top, top / 2, array, target);
    }
    if (array[top - ((top - bottom) / 2)] < target)
    {
        binarysearch(top / 2, bottom, array, target);
    }
}*/

void reverseprinter(char *str, int endreached, int index)
{
    if (*str != '\0' && endreached == 0)
    {
        reverseprinter(str + 1, endreached, ++index);
    }
    else if (index > 0)
    {
        endreached = 1;
        str = str - 1;
        index = index - 1;
        {
            printf("%c", *str);
        }
        reverseprinter(str, endreached, index);
    }
}

int main(void)
{
    int array[10] = {0, 4, 5, 6, 7, 9, 12, 15, 16, 19};
    char *str = malloc(sizeof(char) * 30);
    printf("give a string:");
    scanf("%s", str);
    printf("%s\n", str);
    reverseprinter(str, 0, 0);
    binarysearch(9, 0, array, 6);
    return 0;
}