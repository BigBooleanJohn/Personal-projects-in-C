#include <stdio.h>

/*this program asks for characters to be put in, and will then return a message reading "hello {your name}"
the name must not have any spaces in it, and the name must also be less than 99 characters long.*/
int main(void)
{
    int max_size = 100; //
    char string[max_size - 1];
    printf("tell me your name");
    scanf("%s", string);
    printf("hello %s\n", string);

    return 0;
}