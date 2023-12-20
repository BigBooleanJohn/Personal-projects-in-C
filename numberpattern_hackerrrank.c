#include <stdio.h>

int hasone(int arr[], int x)
{
    int result = 1;
    int ultimate;
    for (int p = 0; p < x; p++)
    {
        if (arr[p] == 1)
            result = 0;
        else
            ultimate = 10;
    }

    return result;
}

void manipulate(int i)
{
    int increment = 1;
    int startingval = i;
    int size = ((i * 2) - 1);
    int lowerbound = 0;
    int upperbound = size - 1;
    int array[size];

    for (int y = 0; y < size; y++)
    {
        array[y] = startingval;
        printf("%d", array[y]);
    }
    printf("\n");

    while (hasone(array, size))
    {
        for (int x = 0; x < size; x++)
        {
            if ((x > lowerbound) && (x < upperbound))
                array[x] = (array[x] - 1);
            else
            {
                array[x] = array[x];
            }
        }
        for (int z = 0; z < size; z++)
        {
            printf("%d", array[z]);
        }
        printf("\n");
        lowerbound = (lowerbound + 1);
        upperbound = (upperbound - 1);
    }
    while (array[1] != startingval)
    {
        for (int e = 0; e < size; e++)
        {
            if (array[e] == increment)
            {
                array[e] = (array[e] + 1);
            }
        }

        for (int z = 0; z < size; z++)
        {
            printf("%d", array[z]);
        }
        printf("\n");
        increment++;
    }
}

int main()
{
    int inte;
    printf("enter a number:");
    scanf("%d", &inte);
    manipulate(inte);
    return 0;
}