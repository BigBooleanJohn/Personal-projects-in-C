#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char arr[50];
    int currdrink = 0;
    int total = 0;
    int done = 1;
    {
        while (done != 0)
        {
            printf("what did you drink today:");
            scanf("%s", arr);
            printf("%s", arr);
            scanf("%d", &done);
        }
        printf("total drinks = %d", total);
    }
}