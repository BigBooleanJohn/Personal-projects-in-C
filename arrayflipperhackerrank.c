#include <stdio.h>

void flippa(int arr[], int variableindex, int base)
{
    if (variableindex <= base)
    {
        printf("done flipping\n");
    }
    else
    {
        int temp = arr[variableindex];
        arr[variableindex] = arr[base];
        arr[base] = temp;
        flippa(arr, --variableindex, ++base);
    }
}

int main()
{
    int count = 0;
    int a[10000];
    int index;

    printf("give numbers: ");
    do
    {
        scanf("%d", &a[count++]);
    } while (getchar() != '\n' && count < 100);

    printf("this is the initial array: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    index = count - 1;

    flippa(a, index, 0);

    printf("this is the final array: ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", a[i]);
    }
}