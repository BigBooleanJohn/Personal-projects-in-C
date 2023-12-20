#include <stdio.h>

char *inttoroman(int inte, char arr[])
{
    int arrofrom[] = {1, 5, 10, 50, 100, 500, 1000};

    char arrofromchar[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int arrOfRomLengthInd = 6;
    int firstind = 0;
    while (inte > 0)
    {
        if ((inte - arrofrom[arrOfRomLengthInd]) < 0)
        {
            arrOfRomLengthInd--;
        }
        else
        {
            arr[firstind] = arrofromchar[arrOfRomLengthInd];
            inte = inte - arrofrom[arrOfRomLengthInd];
            firstind++;
        }
    }
    arr[firstind] = '\0';
    return arr;
}

int main(void)
{
    int inte = 0;
    char finalstring[1000];
    printf("give me an integer:");
    scanf("%d", &inte);
    printf("%s", inttoroman(inte, finalstring));
}