#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printyourstring(void)
{
    printf("give a string:");
    char ch;
    while ((ch = getchar()) != '\n')
    {
        printf("%c", ch);
    }
}

void printfib(int x)
{
    int fibarr[x];
    fibarr[0] = 0;
    fibarr[1] = 1;
    printf("%d%d", fibarr[0], fibarr[1]);
    for (int i = 2; i < x; i++)
    {
        fibarr[i] = fibarr[i - 1] + fibarr[i - 2];
        printf("%d", fibarr[i]);
    }
}

void printRand(int x)
{
    srand((unsigned)time(NULL));
    int z = 0;
    for (int i = 0; i < x; i++)
    {
        z = rand() % 100;
        printf("%d\n", z);
    }
}

int test(int arr[])
{
    return arr[2];
}

int main(void)
{
    printyourstring();
    printf("\n");
    printfib(10);
    printf("\n");
    printRand(10);

    int arr[6] = {0, 8, 5, 22, 33};
    int third = test(arr);
    printf("\n%d\n", third);
}
