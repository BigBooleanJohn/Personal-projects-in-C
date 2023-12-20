#include <stdio.h>
#include <stdlib.h>

/*question one: recursive number adder for n*/
int recursiveadd(int n, int total)
{
    if (n == 0)
    {
        return total;
    }
    else
    {
        total = n + total;
        n--;
        return recursiveadd(n, total);
    }
}
/*------------------------------------------------------------------*/
/*this next function declares the fibonacci number at the given point*/
int fibo_at_n(int n, int indexcount, int arr[n])
{
    arr[0] = 0;
    arr[1] = 1;
    arr[indexcount] = arr[indexcount - 1] + arr[indexcount - 2];
    if (indexcount == n)
    {
        return arr[n - 1];
    }
    else
    {
        return fibo_at_n(n, ++indexcount, arr);
    }
}
/*------------------------------------------------------------------*/
/* the next and final function scans in a string and recursively goes back
and printf it in reverse*/
void reverseprinter(char *str, int endreached, int index)
{
    if (*str != '\0' && endreached == 0)
    {
        reverseprinter(str + 1, endreached, ++index);
    }
    else if (index > 0)
    {
        endreached = 1;
        str = str - 1;
        index = index - 1;
        {
            printf("%c", *str);
        }
        reverseprinter(str, endreached, index);
    }
}

int main(void)
{
    int num = 16;
    int totaladd = 0;
    int fibonum = 5;
    int arr[fibonum];
    int index = 2;
    char *stringg = "john";
    printf("\n\nthe first added are %d\n", recursiveadd(num, totaladd));
    printf("\n\nnow I am going to the fibonacci number procedure");
    printf("the fibo number at %d is %d\n", fibonum, fibo_at_n(fibonum, index, arr));
    printf("\noriginal string is %s\n", stringg);
    reverseprinter(stringg, 0, 0);
    return 0;
}