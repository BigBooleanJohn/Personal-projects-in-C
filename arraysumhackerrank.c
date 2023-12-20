#include <stdio.h>

int main()
{
    int count = 0;
    int size = 10000;
    int a[size];
    printf("give me a bunch of numbers:");

    do
    {
        scanf("%d", &a[count++]);
    } while (getchar() != '\n' && count < 100);

    a[count];
    int sum = 0;

    for (int b = 0; b < count; b++)
    {
        printf("%d ", a[b]);
        sum = sum + a[b];
    }
    printf("\n");
    printf("%d\n", sum);
}
