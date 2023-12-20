#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int absvalsubtract(int a, int b)
{
    int final = 0;
    if ((a - b) < 0)
    {
        final = ((a - b) * -1);
    }
    else
    {
        final = a - b;
    }
    return final;
}

void bucket(int *height, int size)
{
    int maxtracker[] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < size; i++)
    {
        int currentheight = height[i];
        int currentindex = i;
        int variableindex = 0;
        int volume = 0;
        while (variableindex < size)
        {
            if (currentheight <= height[variableindex])
            {
                volume = currentheight * absvalsubtract(currentindex, variableindex);
            }
            else
            {
                volume = height[variableindex] * absvalsubtract(currentindex, variableindex);
            }
            if (maxtracker[0] < volume)
            {
                maxtracker[0] = volume;
                maxtracker[1] = currentindex;
                maxtracker[2] = variableindex;
                maxtracker[3] = currentheight;
                maxtracker[4] = height[variableindex];
            }
            variableindex = variableindex + 1;
        }
    }
    printf("the maximum volume of this bucket graph is %d, the two indices of the sides are %d and %d, and the heights of the walls were %d and %d\n",
           maxtracker[0], maxtracker[1], maxtracker[2], maxtracker[3], maxtracker[4], maxtracker[5]);
}

int main(void)
{
    int numarr[100];
    srand((unsigned)time(NULL));
    for (int i = 0; i < 15; i++)
    {
        numarr[i] = ((rand() % 50) + 1);
    }
    bucket(numarr, 15);
}