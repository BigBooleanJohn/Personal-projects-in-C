#include <stdio.h>

/*int mintix(int costs[], int daystraveled[], int numofdaystraveled)
{
    int currenttravelday = 0;
    int couldbebestoption = 1;
    while (currenttravelday < numofdaystraveled)
    {
        if (couldbebestoption)
        {
            for (int i = 0; i < 7)
        }
    }
}*/

int main(void)
{
    int costs[3] = {2, 7, 15};
    int lowestmincosts[100] = {};
    int totalcost = 0;
    int numoftraveldays = 0;
    printf("how many days will you travel for:");
    scanf("%d", &numoftraveldays);
    int traveldays[numoftraveldays];
    printf("what days will those be?");
    for (int i = 0; i < numoftraveldays; i++)
    {
        scanf("%d", &traveldays[i]);
    }
}