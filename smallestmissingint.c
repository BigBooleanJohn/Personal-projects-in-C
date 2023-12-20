/*this procedure takes an unsorted array of integers, and finds the lowest missing integer in the array*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lowestmissing(int arr[], int length)
{
    int verylowest = 1;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] <= verylowest)
        {
            verylowest++;
        }
        else if (verylowest > 99)
        {
            printf("every integer between 1 and 100 is in the array, and the smallest missing value is 100\n");
            i = length; // this line of code to break out of the loop
        }
    }
    return verylowest;
}

int main(void)
{
    int maxsize = 10000;
    int numofvals = 0;
    int arr[maxsize];
    int smallestmissingint = 0;
    srand((unsigned)time(NULL)); // seeding the random function
    printf("this program will take an array and tell you the smallest positive missing int in the array\n");
    printf("give me the number of values you want in the array, I will then generate that many random numbers in the array:");
    scanf("%d", &numofvals);
    for (int i = 0; i < numofvals; i++)
    {
        arr[i] = ((rand() % 100) + 1);
    }
    smallestmissingint = lowestmissing(arr, numofvals);
    printf("the smallest missing integer in the array is %d\n", smallestmissingint);
}
