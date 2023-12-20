#include <stdio.h>
#include <stdlib.h>
/* candy is a personal programming project aimed to solve the following problem: There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children. */

/*minvals is a helper method used to determine the children in line who's ratings are minimums,
that is, they dont need as much candy.*/
/* preconditions: ratings is a valid array of integers, and length is a valid index representing it's length*/
/* post: returns a pointer to an array of minimum indices*/
int *minvals(int ratings[], int length)
{
    int *ptr;
    int nummins = 0;
    int temparr[length];
    int index = 0;
    for (int i = 0; i < length; i++)
    {
        if (i == 0 && ratings[i] <= ratings[i + 1])
        {
            temparr[index] = i;
            index++;
        }
        else if (i == (length - 1) && ratings[i] <= ratings[i - 1])
        {
            temparr[index] = i;
            index++;
        }
        else if (ratings[i] <= ratings[i + 1] && ratings[i] <= ratings[i - 1])
        {
            temparr[index] = i;
            index++;
        }
    }
    ptr = malloc(sizeof(int) * index);
    for (int x = 0; x < index; x++)
    {
        ptr[x] = temparr[x];
        printf("%d ", ptr[x]);
    }

    return ptr;
}

/*processor takes the array of minimum indices, along with the ratings array, and their respective
lengths, and uses them to compute the minimum amount of candy needed to distribute*/
/* pre: min_indices, *ratings is a valid pointer to an integer array, and their lengths are properly
represented by min_indices_length and ratings_length*/
/* post: returns a pointer to an integer representing the minimum amount of candy */
int *processor(int *min_indexes, int min_indexes_length, int *ratings, int ratings_length)
{
    int index = 0;
    int i = 0;
    int candyarr[ratings_length];
    for (int i = 0; i < min_indexes_length; i++)
    {
        candyarr[min_indexes[i]] = 1;
    }

    for (int x = min_indexes[0]; x > 0; x--)
    {
        if (ratings[x - 1] > ratings[x])
        {
            candyarr[x - 1] = candyarr[x] + 1;
        }
        else if (ratings[x - 1] < ratings[x])
        {
            candyarr[x - 1] = candyarr[x] - 1;
        }
    }
    for (int i = 0; i < min_indexes_length; i++)
    {
        for (int j = min_indexes[i]; j < min_indexes[i + 1]; j++)
        {
            if (ratings[j + 1] > ratings[j])
            {
                candyarr[j + 1] = candyarr[j] + 1;
            }
            else if (ratings[j + 1] < ratings[j])
            {
                candyarr[j + 1] = candyarr[j] - 1;
            }
        }
    }
    for (int y = min_indexes[min_indexes_length - 1]; y < ratings_length; y++)
    {
        if (ratings[y + 1] > ratings[y])
        {
            candyarr[y + 1] = candyarr[y] + 1;
        }
        else if (ratings[y + 1] < ratings[y])
        {
            candyarr[y + 1] = candyarr[y] - 1;
        }
    }
    int *candypointer = malloc(sizeof(int) * ratings_length);
    int total = 0;
    for (int z = 0; z < ratings_length; z++)
    {
        candypointer[z] = candyarr[z];
        total += candypointer[z];
        printf("%d ", candypointer[z]);
    }
    return candypointer;
}

/* main method */
int main(void)
{
    int numkids = 0;
    printf("how many children are there?");
    scanf("%d", &numkids);
    printf("gimme their ratings:");
    int ratingsarr[numkids];
    for (int i = 0; i < numkids; i++)
    {
        scanf("%d", &ratingsarr[i]);
        printf("%d ", ratingsarr[i]);
    }
    printf("\n");
    int *minimums = minvals(ratingsarr, numkids);
    int *result = processor(minimums, 1, ratingsarr, numkids);
    printf("the minimum amount of candy we can give is %d\n", *result);
    return 0;
}