/*this is a program that prints every possible iteration of parentheses*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 50
#define MAX_CHARS 100

typedef struct queue queue_t;
struct queue
{
    int first;
    int count;
    char *quarr[MAX_LENGTH];
};

bool isFull(queue_t *queue)
{
    if (queue->count == MAX_LENGTH - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty(queue_t *queue)
{
    if (queue->quarr[queue->first] == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*makes and initializes an array*/
queue_t *initialize(void)
{
    queue_t *makequeue = malloc(sizeof(queue_t) * 1);
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        makequeue->quarr[i] = NULL;
    }
    makequeue->first = 0;
    makequeue->count = 0;
    return makequeue;
}

/*takes off the first element of the queue*/
char *dequeue(queue_t *queue)
{
    // first, I gotta find the length of the string
    int i = 0;
    char *ch = queue->quarr[queue->first];
    while (*ch != '\0')
    {
        printf("current char is %c, current index is %d", *ch, i);
        i++;
        ch = ch + 1;
    }
    char *returnStr = malloc(sizeof(char) * i + 1);
    strcpy(returnStr, queue->quarr[queue->first]);
    if (queue->first == MAX_LENGTH - 1)
    {
        queue->first = 0;
        queue->count--;
        queue->quarr[MAX_LENGTH - 1] = NULL;
    }
    else
    {
        queue->first = queue->first + 1;
        queue->count--;
        queue->quarr[MAX_LENGTH - 1] = NULL;
    }
    return returnStr;
}

queue_t *enqueue(queue_t *queue)
{
    if (isFull(queue))
    {
        printf("the queue is full");
        return NULL;
    }
    else
    {
        printf("what is the string you want to put in:");
        char ch[MAX_CHARS];
        int i = 0;
        char chh;
        while ((chh = getchar()) != '\n')
        {
            ch[i] = chh;
            i++;
        }
        ch[i] = '\0';
        char *finalStr = malloc(sizeof(char) * i);
        strcpy(finalStr, ch);
        queue->quarr[queue->count] = finalStr;
        printf("%s\n", queue->quarr[queue->count]);
        queue->count++;
        return queue;
    }
}

int main(void)
{
    queue_t *Johnsqueue = initialize();
    Johnsqueue = enqueue(Johnsqueue);
    Johnsqueue = enqueue(Johnsqueue);
    printf("is it empty = %d\n, johnsqueue first = %d, count = %d\n", isEmpty(Johnsqueue), (*Johnsqueue).first, (*Johnsqueue).count);
}