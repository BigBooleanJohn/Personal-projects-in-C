
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
