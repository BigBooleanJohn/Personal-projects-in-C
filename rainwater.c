#include <stdio.h>

/*making a column here to keep track of shiiiii. This program is for the leetcode problem "trapping rain water" */

/*this function takes an array and it's length, and initializes it to zero*/
void zeroinitialize(int arr[], int leng)
{
    for (int i = 0; i < leng; i++)
    {
        arr[i] = 0;
    }
}

/*this is a helper function that flips the values in an array*/
void arrayswap(int array[], int length)
{
    int lowval = 0;
    int highval = length - 1;

    while (lowval < highval)
    {
        int temp = array[lowval];
        array[lowval] = array[highval];
        array[highval] = temp;
        lowval++;
        highval--;
    }
}

/*this is a function that returns the highest value in the array of integers*/
int returnsbiggest(int arr[], int length)
{
    int currentbigindex = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > arr[currentbigindex])
        {
            currentbigindex = i;
        }
    }
    return currentbigindex;
}

/*this function takes the "maxes" i.e. the values that could capture rainwater, and then calculates how much water can be held to the left of the
max value in the full inputted array*/
int rainwaterfinalleft(int arrofmaxesleft[], int maxesleftlength, int fullarr[])
{
    printf("left maxes array length is %d\n", maxesleftlength);
    int firstindex = 0;
    int secondindex = 1;
    int truee = 1;
    if (maxesleftlength == 1)
    {
        truee = 0;
    }
    int sum = 0;
    int forsum = 0;
    int maxamountinlastbucket;

    while (truee)
    {
        if (secondindex >= (maxesleftlength - 1))
        {
            sum += (fullarr[arrofmaxesleft[firstindex]] * (((arrofmaxesleft[secondindex] - arrofmaxesleft[firstindex]) - 1)));
            for (int i = ((arrofmaxesleft[firstindex]) + 1); i < arrofmaxesleft[secondindex]; i++)
            {
                sum = sum - fullarr[i];
            }
            truee = 0;
        }
        else if (fullarr[arrofmaxesleft[firstindex]] < fullarr[arrofmaxesleft[secondindex]])
        {
            sum += (fullarr[arrofmaxesleft[firstindex]] * (((arrofmaxesleft[secondindex] - arrofmaxesleft[firstindex]) - 1)));
            for (int i = ((arrofmaxesleft[firstindex]) + 1); i < arrofmaxesleft[secondindex]; i++)
            {
                sum = sum - fullarr[i];
            }
            firstindex = secondindex;
            secondindex++;
        }
        else
        {
            secondindex++;
        }
    }
    return sum;
}

/*this function takes the "maxes" i.e. the values that could capture rainwater, and then calculates how much water can be held to the right of the
max value in the full inputted array*/
int rainwaterfinalright(int arrofmaxesright[], int maxesrightlength, int fullarr[])
{
    int truee = 1;
    printf("this is maxesrightlength: %d\n", maxesrightlength);
    if (maxesrightlength == 1)
    {
        truee = 0;
    }
    int firstindex = maxesrightlength - 1;
    int secondindex = maxesrightlength - 2;
    int summ = 0;
    while (truee)
    {
        if (secondindex == 0)
        {
            summ += (fullarr[arrofmaxesright[firstindex]] * ((arrofmaxesright[firstindex] - arrofmaxesright[secondindex]) - 1));
            for (int i = (arrofmaxesright[firstindex] - 1); i > arrofmaxesright[secondindex]; i--)
            {
                summ = summ - fullarr[i];
            }
            printf("last bucket sum is %d", summ);
            truee = 0;
        }
        else if (fullarr[arrofmaxesright[secondindex]] > fullarr[arrofmaxesright[firstindex]])
        {
            summ += (fullarr[arrofmaxesright[firstindex]] * ((arrofmaxesright[firstindex] - arrofmaxesright[secondindex]) - 1));
            for (int i = (arrofmaxesright[firstindex] - 1); i > arrofmaxesright[secondindex]; i--)
            {
                summ = summ - fullarr[i];
            }
            printf("first bucket sum is %d", summ);
            firstindex = secondindex;
            secondindex--;
        }
        else
        {
            secondindex--;
        }
    }
    return summ;
}

/*this is the "bread and butter" function. It takes an array, it's length, and calls the "returns biggest" helper function on the
array. from this, the function then uses the index of the largest value to check where other indices could form basins that hold
rainwater, and stores those values in separate arrays*/
void rainwaterhelper(int arr[], int length)
{
    int highestval = returnsbiggest(arr, length);
    printf("our max val INDEX is %d\n\n", highestval);
    int highestvalright = highestval;
    int highestvalleft = highestval;
    int foldleftvar = highestval;
    int foldrightvar = highestval;
    int canholdwaterright = 0;

    int waterrightarr[100];
    zeroinitialize(waterrightarr, 100);
    int sumwaterrightindex = 1;
    waterrightarr[0] = highestvalright;

    while (foldrightvar < length)
    {
        if (arr[foldrightvar] >= arr[foldrightvar + 1])
        {
            foldrightvar++;
            if (foldrightvar >= length)
            {
                printf("Rightfold: there is no water to be possibly stored from the index %d to the right\n", highestvalright);
            }
        }
        else
        {
            printf("Rightfold: there can be water stored between %d and %d\n", highestvalright, (foldrightvar + 1));
            highestvalright = foldrightvar + 1;
            waterrightarr[sumwaterrightindex++] = highestvalright; // stores the value in the array
            foldrightvar++;
        }
    }
    printf("these are the values of the right maxes:");
    for (int x = 0; x < sumwaterrightindex; x++)
    {
        printf("%d ", waterrightarr[x]);
    }
    printf("\n\n");

    int sumwaterleftindex = 1;
    int waterleftarr[100];
    zeroinitialize(waterleftarr, 100);
    waterleftarr[0] = highestvalleft;
    while (foldleftvar > 0)
    {
        if ((arr[foldleftvar] >= arr[foldleftvar - 1]))
        {
            foldleftvar--;
            if (foldleftvar == 0)
            {
                printf("leftfold: there is no water to be possibly stored from the index %d to the left\n", highestvalleft);
            }
        }
        else
        {
            printf("leftfold: there can be water stored between %d and %d\n", highestvalleft, (foldleftvar - 1));
            highestvalleft = foldleftvar - 1;
            waterleftarr[sumwaterleftindex++] = highestvalleft; // stores the value in the array
            foldleftvar--;
        }
    }
    arrayswap(waterleftarr, sumwaterleftindex);
    printf("these are the values of the left maxes:");
    for (int x = 0; x < sumwaterleftindex; x++)
    {
        printf("%d ", waterleftarr[x]);
    }
    printf("\n\n");
    printf("to the right, we can hold %d units of rain\n", rainwaterfinalright(waterrightarr, sumwaterrightindex, arr));
    printf("to the left, we can hold %d units of rain\n\n\n", rainwaterfinalleft(waterleftarr, sumwaterleftindex, arr));
    printf("this this how much total water we can hold: %d\n", rainwaterfinalright(waterrightarr, sumwaterrightindex, arr) + rainwaterfinalleft(waterleftarr, sumwaterleftindex, arr));
    /*the lines of code above call our helper functions, whih allow us to add the combined potential rain stored on both sides and
    add it up to find the total rainwater.*/
}

int main(void)
{
    int numvals = 0;
    printf("give me a number of values:");
    scanf("%d", &numvals);
    printf("give %d number of array vals:", numvals);
    int rainarr[100];
    zeroinitialize(rainarr, 100);
    for (int i = 0; i < numvals; i++)
    {
        scanf("%d", &rainarr[i]);
    }
    rainwaterhelper(rainarr, numvals);
}