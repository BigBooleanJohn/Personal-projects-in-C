#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*void letterCombinations(char *num)
{
    char *two = "abc";
    char *three = "def";
    char *four = "ghi";
    char *five = "jkl";
    char *six = "mno";
    char *seven = "pqrs";
    char *eight = "tuv";
    char *nine = "wxyz";

    int strlength = strlen(num);
    printf("string length is %d\n", strlength);
    int totalcombos = 1;
    for (int i = 0; i < strlength; i++)
    {
        if ((num[i] - '0') == 2 || (num[i] - '0') == 3 || (num[i] - '0') == 4 || (num[i] - '0') == 5 || (num[i] - '0') == 6 || (num[i] - '0') == 8)
        {
            totalcombos = totalcombos * 3;
            printf("this is the current totalcombos: %d", totalcombos);
        }
        else if ((num[i] - '0') == 7 || (num[i] - '0') == 9)
        {
            totalcombos = totalcombos * 4;
            printf("this is the current totalcombos: %d", totalcombos);
        }
    }
    printf("gor here. total combos is %d\n", totalcombos);
    if (strlength == 1)
    {
        char *numarr1;
        char *numarr2;
        if ((num[0] - '0') == 2)
        {
            printf("%c %c %c\n", two[0], two[1], two[2]);
        }
        else if ((num[0] - '0') == 3)
        {
            printf("%c %c %c\n", three[0], three[1], three[2]);
        }
        else if ((num[0] - '0') == 4)
        {
            printf("%c %c %c\n", four[0], four[1], four[2]);
        }
        else if ((num[0] - '0') == 5)
        {
            printf("%c %c %c\n", five[0], five[1], five[2]);
        }
        else if ((num[0] - '0') == 6)
        {
            printf("%c %c %c\n", six[0], six[1], six[2]);
        }
        else if ((num[0] - '0') == 7)
        {
            printf("%c %c %c %c\n", seven[0], seven[1], seven[2], seven[3]);
        }
        else if ((num[0] - '0') == 8)
        {
            printf("%c %c %c\n", eight[0], eight[1], eight[2]);
        }
        else if ((num[0] - '0') == 9)
        {
            printf("%c %c %c %c\n", nine[0], nine[1], nine[2], nine[3]);
        }
    }
    printf("gor here. total combos is %d\n", totalcombos);

    //////////////////////////////


    if (strlength == 2)
    {


        if ((num[0] - '0') == 2)
        {

        }
        else if ((num[0] - '0') == 3)
        {
            printf("%c %c %c\n", three[0], three[1], three[2]);
        }
        else if ((num[0] - '0') == 4)
        {
            printf("%c %c %c\n", four[0], four[1], four[2]);
        }
        else if ((num[0] - '0') == 5)
        {
            printf("%c %c %c\n", five[0], five[1], five[2]);
        }
        else if ((num[0] - '0') == 6)
        {
            printf("%c %c %c\n", six[0], six[1], six[2]);
        }
        else if ((num[0] - '0') == 7)
        {
            printf("%c %c %c %c\n", seven[0], seven[1], seven[2], seven[3]);
        }
        else if ((num[0] - '0') == 8)
        {
            printf("%c %c %c\n", eight[0], eight[1], eight[2]);
        }
        else if ((num[0] - '0') == 9)
        {
            printf("%c %c %c %c\n", nine[0], nine[1], nine[2], nine[3]);
        }
    }
}*/

void makesallcombos(char *strone, char *strtwo)
{
    int totalcombos = strlen(strone) * strlen(strtwo) * 2;
    char *strcombos = malloc(sizeof(char) * (3 * totalcombos));
    int indexofs1, indexofs2, indexofs3;
    int index = 0;
    int counter = 0;
    int secondcounter = 0;
    for (int i = 0; i < totalcombos; i = i + 2)
    {
        strcombos[i] = strone[index];
        counter++;
        if (counter == 3)
        {
            index++;
            counter = 0;
        }
    }
    for (int x = 1; x < totalcombos; x = x + 2)
    {
        strcombos[x] = strtwo[secondcounter];
        secondcounter++;
        if (secondcounter == 3)
        {
            secondcounter = 0;
        }
    }
    int p = 0;
    while (p < 18)
    {
        printf("%c%c ", strcombos[p], strcombos[p + 1]);
        p = p + 2;
    }
}
int main(void)
{
    char *s1;
    char *s2;

    /*printf("ill make every combo of letters from two 3 letter strings:");
    scanf("%s %s", s1, s1);
    printf("%s\n", s1);
    printf("%s\n", s2);
     makesallcombos(s1, s2);*/
    char *str = "bad";
    printf("%lu\n", strlen(str));

    return 0;
}
