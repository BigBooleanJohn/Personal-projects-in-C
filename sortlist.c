#include <stdio.h>
#include <stdlib.h>

/*this function sorts a list from largest to smallest */

typedef struct node node_t;
struct node
{
    int val;
    node_t *next;
};

int issorted(node_t *head)
{
    int *inte = malloc(sizeof(int) * 1);
    *inte = 1;
    int value = 0;
    int prev = (*head).val;

    while (head != NULL)
    {
        if ((*head).val <= prev)
        {
            prev = (*head).val;
            head = (*head).next;
        }
        else
        {
            *inte = 0;
            head = NULL;
        }
    }
    return *inte;
}
void printlist(node_t *head)
{
    while (head != NULL)
    {
        printf("%d ", (*head).val);
        head = (*head).next;
    }
    printf("\n");
}

node_t *sortedlist(node_t *head)
{
    node_t *headcopy = head;
    int temp = 0;
    while (issorted(headcopy) == 0)
    {
        if ((*head).next == NULL)
        {
            head = headcopy; /*if the next node is null, then jump back to the front of the list*/
        }
        if ((*head).val < (*(*head).next).val) // if the current value of the node is less than the next
        {
            temp = (*head).val;
            (*head).val = (*(*head).next).val; // swap the two values
            (*(*head).next).val = temp;
            head = (*head).next;
            printlist(headcopy);
        }
        else
        {
            head = (*head).next;
            printlist(headcopy);
        }
    }
    head = headcopy;
    return head;
}

int main(void)
{
    node_t *a;
    node_t *b;
    node_t *c;
    node_t *d;
    node_t *e;
    node_t *f;
    node_t *g;
    a = malloc(sizeof(node_t) * 1);
    b = malloc(sizeof(node_t) * 1);
    c = malloc(sizeof(node_t) * 1);
    d = malloc(sizeof(node_t) * 1);
    e = malloc(sizeof(node_t) * 1);
    f = malloc(sizeof(node_t) * 1);
    g = NULL;
    (*a).next = b;
    (*a).val = 1;
    (*b).next = c;
    (*b).val = 4;
    (*c).val = 7;
    (*d).val = 2;
    (*e).val = 9;
    (*f).val = 5;
    (*c).next = d;
    (*d).next = e;
    (*e).next = f;
    (*f).next = g;

    sortedlist(a);
    return 0;
}