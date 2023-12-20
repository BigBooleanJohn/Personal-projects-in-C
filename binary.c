#include <stdio.h>
#include <stdlib.h>

int binarysearch(int top, int bottom, int array[], int target)
{
    if (array[(top + bottom) / 2] == target)
    {
        return (top + bottom) / 2;
    }
    if (array[(top + bottom) / 2] < target)
    {
        binarysearch(top, (top / 2) + 1, array, target);
    }
    if (array[(top + bottom) / 2] > target)
    {
        binarysearch((top / 2) - 1, bottom, array, target);
    }
}

int main(void)
{
    int array[10] = {0, 4, 5, 6, 7, 9, 12, 15, 16, 19};
    printf("%d\n", binarysearch(9, 0, array, 16));
}