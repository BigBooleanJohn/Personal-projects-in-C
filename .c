#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRMAX 50
/* maximum size of a string within a list node */

typedef struct node node_t;

struct node
{
    char data[STRMAX + 1]; /* Additional slot for sentinel */
    node_t *next;
};

char *substr(int beginning, int end, char *startingstr)
{
    int x = 0;
    int substringlength = ((end - beginning) + 1);
    char *substring = malloc(sizeof(char) * substringlength);
    for (int i = beginning; i < end; i++)
    {
        substring[x++] = startingstr[i];
    }
    substring[substringlength] = '\0';
    return substring;
}

int strrlen(char *str)
{
    int x = 0;
    while (str[x] != '\0')
    {
        x++;
    }
    return x;
}
/* ---------------------------------------------------------------- */
/* function prototypes, listed in alphabetical order */

char *cadr(node_t *list)
{
    char *nextdata = malloc(sizeof(char) * (STRMAX + 1));
    node_t *nextnode = (*list).next;

    if (nextnode != NULL)
    {
        strcpy(nextdata, (*nextnode).data);
        printf("the next data is %s\n", nextdata);
    }
    else
    {
        printf("the next node is null");
    }
    return nextdata;
}
void listPrint(node_t *list)
{
    int x = 0;
    while (list != NULL)
    {
        printf("data at node %d is %s", x, (*list).data);
        x++;
        list = (*list).next;
    }
}

int numoccurenceshelper(char *strlooks, node_t *list, int numoccurences)
{
    char *currentchar = (*list).data;
    int start = 0;
    int end = start + strrlen(strlooks);
    while (end <= strrlen(currentchar))
    {
        char *substring = substr(start, end, currentchar);
        if (strcmp(strlooks, substring) == 0)
        {
            numoccurences++;
            start++;
            end++;
        }
        else
        {
            start++;
            end++;
        }
    }
    return numoccurences;
}

int numoccur(char *strlook, node_t *currnode)
{
    int *intPtr = malloc(sizeof(int) * 1);
    node_t *currentnode = currnode;
    while (currentnode != NULL)
    {
        *intPtr += numoccurenceshelper(strlook, currnode, 0);
        currentnode = (*currentnode).next;
    }
    return *intPtr;
}

/* declarations */
node_t *a = NULL;
node_t *b;
node_t *c;
node_t *d;
node_t *e;
char *str;

node_t *
cons(char *newData, node_t *rest)
{
    /* pre-condition:  newData is an initialized string
                       rest is an initialized list
       post-condition: returns new node with newData copied to data field
                       and next field pointing to rest
                       if new node cannot be allocated, returns NULL and prints error
    */
    node_t *newNode = (node_t *)malloc(sizeof(node_t));

    if (newNode == NULL)
    {
        perror("Unable to allocate node");
        return NULL;
    }
    strncpy(newNode->data, newData, STRMAX + 1); /* limit copy to avoid overflow */
    newNode->next = rest;                        /* define next field of node as the rest of the list */
    return newNode;                              /* return newly initialized node */
}
/* create lists */

struct node node1 = {"dacsddsmx"};

int main(int argc, char *argv[])
{
    char *arr = "suckxx mz fzt ciik";
    char *artwo = "abc";
    printf("%s\n", arr);
    printf("%s \n", substr(0, 2, arr));
    printf("%d\n", strrlen(artwo));
    node_t *z = NULL;
    b = cons("node B", z);
    c = cons("node C", b);
    d = cons("node D", c);

    listPrint(d);

    printf("there are %d occurences of %s", numoccur("z", d), "z");

    return 0;
}
