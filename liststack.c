#include <stdio.h>
#include <stdlib.h>
#define MAXCHARS 50

typedef struct stacknode stacknode_t;
typedef struct stack stack__t;
struct stacknode
{
    char stringdata[MAXCHARS];
    stacknode_t *nextnode;
};

struct stack
{
    int topstacknum;
    stacknode_t *topnode;
};

// pop function that removes the top value of the stack
void pop(stack__t *stack)
{
    (*stack).topstacknum--;
    stacknode_t *temp = (*stack).topnode;
    (*stack).topnode = (*(*stack).topnode).nextnode;
    free(temp);
}

// top function that returns the top of the stack
stacknode_t *top(stack__t *stack)
{
    print("the top of the stack has number %d\n and string data %s\n", (*stack).topstacknum, (*(*stack).topnode).stringdata);
    return (*stack).topnode;
}

// push function that adds another node to the stack
void push(stack__t *stack)
{
    stacknode_t *newtop = malloc(sizeof(stacknode_t) * 1);
    printf("what is the string:");
    char ch;
    int i = 0;
    scanf("%s", (*newtop).stringdata);
    if ((*stack).topnode == NULL)
    {
        (*stack).topstacknum = 0;
    }
    else
    {
        (*stack).topstacknum++;
    }
    (*newtop).nextnode = (*stack).topnode;
    (*stack).topnode = newtop;
}

// stack printing function
void stackprinter(stack__t *stack)
{
    printf("the top of the stack has number %d\n", (*stack).topstacknum);
    printf("these are the strings in the stack:");
    stacknode_t *currnode = (*stack).topnode;
    while (currnode != NULL)
    {
        printf("%s  ", (*currnode).stringdata);
        currnode = (*currnode).nextnode;
    }
}

int main(void)
{
    stack__t *stack1 = malloc(sizeof(stack__t));
    int option = 1;
    while (option != 4)
    {
        printf("perform the operation that you wish. 1: pop, 2: top, 3:push 4: end:\n");
        scanf("%d", &option);
        if (option == 1)
        {
            pop(stack1);
        }
        else if (option == 2)
        {

            top(stack1);
        }
        else if (option == 3)
        {
            push(stack1);
        }
    }
    stackprinter(stack1);

    return 0;
}