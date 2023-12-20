/* this program is going to take an array of values and an number i, and this program will return the indices of
the values of the array that add to the number*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

void arraymaker(int length, int valsize, int arr[])
{
    for (int i = 0; i < length; i++)
    {
        int x = rand() % 100;
        arr[i] = x;
    }
}

void checker(int i, int arr[], int lengthofarray)
{

    for (int currentindex = 0; currentindex < lengthofarray; currentindex++)
    {
        int notequal = 1;
        int hasprinted = 0;
        int variableindex = 0;

        while (notequal)
        {
            if (arr[currentindex] + arr[variableindex] == i)
            {
                printf("success! the value at index %d and the value at index %d add up to %d. those values were %d & %d\n", currentindex, variableindex, i, arr[currentindex], arr[variableindex]);
                notequal = FALSE;
                hasprinted = TRUE;
            }
            else if (variableindex == lengthofarray)
            {
                notequal = FALSE;
            }
            else
            {
                variableindex++;
            }
        }
        if ((currentindex == lengthofarray - 1) && (hasprinted == 0))
        {
            printf("we have reached the end of the array, and there were no values that added to your value!\n");
        }
    }
}

int main(void)
{
    int length = 0;
    int sumnumber;
    int maxnums = 10000;
    int randomarray[maxnums];
    srand((unsigned)time(NULL));
    printf("this program takes a value and establishes an array of random values less than 100. the\n program returns the indices that sum to this number\n");
    printf("how long do you want your array to be? it must be big! can't make it too easy");
    scanf("%d", &length);
    arraymaker(length, 100, randomarray);
    printf("\n\n");
    printf("the array is ready. what is your input numer? it should be less than 100:");
    scanf("%d", &sumnumber);
    checker(sumnumber, randomarray, length);
}
