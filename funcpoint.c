#include <stdio.h>

int dafunkyy(int x, int y, int z)
{
    return x + y + z;
}

int main(void)
{
    int (*Pfunk)(int, int, int);

    Pfunk = &dafunkyy;

    printf("%d", (*Pfunk)(3, 5, 9));

    return 0;
}