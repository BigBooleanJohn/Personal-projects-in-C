#include <stdio.h>
#define MAX_SIZE 100
#define ENDVAL -1

void sortingalgorithm(int arr[], int length)
{
    for (int iteration = 0; iteration < length; iteration++)
    {
        int index = 0;
        while (index < length)
        {
            if (arr[index] <= arr[index + 1])
            {
                index++;
            }
            else
            {
                int temp = arr[index];
                arr[index] = arr[index + 1];
                arr[index + 1] = temp;
                index++;
            }
        }
    }
}

/*this function will take an array, and find it's base permutation, which is just the listing of the
values from smallest to largest*/
void nextpermutation(int arr[])
{
}

int main(void)
{
    int sizeofarray = 0;
    printf("give me the length of the array:");
    scanf("%d", &sizeofarray);
    int arr[sizeofarray];
    printf("give me the values that you want to permutate:");
    int numscanned = 0;
    for (int i = 0; i < sizeofarray; i++)
    {
        scanf("%d", &arr[i]);
    }
}