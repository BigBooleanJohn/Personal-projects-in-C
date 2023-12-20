#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node_t;
typedef struct queue queue_t;
struct node
{
    char *data;
    struct node *next;
};
struct queue
{
    int count;
    struct node *head;
};

queue_t *def_and_init(int numnodes)
{
    queue_t *finalqueue = malloc(sizeof(queue_t) * 1);
    (*finalqueue).head = NULL;
    (*finalqueue).count = 0;
    node_t *headcopy;
    char temparr[50];
    for (int i = 0; i < numnodes; i++)
    {
        node_t *newnode = malloc(sizeof(node_t) * 1);
        char str[50];
        if ((*finalqueue).head == NULL)
        {
            printf("give me a string:");
            scanf("%s", str);
            int length = strlen(str);
            (*newnode).data = malloc(sizeof(char) * (length + 1));
            strcpy((*newnode).data, str);
            (*newnode).next = NULL;
            headcopy = newnode;
            (*finalqueue).head = newnode;
            (*finalqueue).count++;
        }
        else
        {
            printf("what is the string:");
            scanf("%s", str);
            int length = strlen(str);
            (*newnode).data = malloc(sizeof(char) * (length + 1));
            strcpy((*newnode).data, str);
            (*newnode).next = NULL;
            while ((*(*finalqueue).head).next != NULL)
            {
                (*finalqueue).head = (*(*finalqueue).head).next;
            }
            (*(*finalqueue).head).next = newnode;
            (*finalqueue).count++;
        }
    }
    (*finalqueue).head = headcopy;
    return finalqueue;
}

void printqueue(queue_t *queue)
{
    printf("there are %d nodes\n", (*queue).count);
    node_t *tempq = (*queue).head;
    while (tempq != NULL)
    {
        printf("%s ", (*tempq).data);
        tempq = (*tempq).next;
    }
}

char *front(queue_t *queue)
{
    node_t *temp = (*queue).head;
    char *ref = temp->data;
    free(temp);
    return ref;
}
int main(void)
{
    queue_t *que = def_and_init(7);
    // printqueue(que);
    char *strfront = front(que);
    printf("front string is %s\n", strfront);
    // printqueue(que);
    //  printf("\n%s\n", (*(*que).head).data);
    return 0;
}