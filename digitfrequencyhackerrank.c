

#include <stdio.h>

int evaluate(char c)
{
    int currentval;
    currentval = c - '0';
    return currentval;
}

void arraymanipulate(int ar[], int atwo[], int n)
{
    int i;
    int irrelevant;
    for (i = 0; i < n; i++)
        if ((ar[i] < 10) && (ar[i] >= 0))
        {
            atwo[ar[i]]++;
        }
        else
            irrelevant++;
}

void arrayprinter(int arrr[], int n)
{
    int p;
    for (p = 0; p < n; p++)
    {
        printf("%d ", arrr[p]);
    }
}

int main()
{
    int arr[10000];
    int finalarray[10];
    int index = 0;
    char newin;
    int newline = -38;
    int input;
    printf("give me a string of numbers and characters:");

    while (input != newline)
    {
        scanf("%c", &newin);
        input = evaluate(newin);
        if (input == -38)
        {
            input = newline;
        }
        else
        {
            arr[index++] = input;
        }
    }
    index = index - 1;
    arr[index];
    arraymanipulate(arr, finalarray, index);
    printf("these are the frequencies of each numeric value in the string from 0 to 10\n");
    arrayprinter(finalarray, 10);
}