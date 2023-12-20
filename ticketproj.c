#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHARS 50

typedef struct ticket ticket_t;

struct ticket // declaring the ticket structure
{
    int ticketnum;
    char companyident[MAXCHARS + 1];
    char issuecode[MAXCHARS + 1];
    char status[10];
    char technicianname[MAXCHARS + 1];
    ticket_t *next;
};

/* this function takes pointers to the heads of both the assigned and completed
ticket lists, and returns to us th head of the updated ticket list.

preconditions: assignedtix and completedtix are valid pointers, can be null
postconditions: the completedtix head that is returned mus be valid, but can be null*/
ticket_t *completedtix(ticket_t *assignedtix, ticket_t *completedtix)
{
    printf("you have entered the complete-ticket function\n");
    ticket_t *completedtixcopy = (ticket_t *)malloc(sizeof(ticket_t *));
    completedtixcopy = completedtix;
    int *intPtr = malloc(sizeof(int) * 1);
    printf("what is the ticket that is complete?");
    scanf("%d", intPtr);
    printf("now looking for ticket %d\n", *intPtr);
    ticket_t *compticket = NULL;
    ticket_t *prev = NULL;
    while (assignedtix != NULL)
    {
        if ((*assignedtix).ticketnum == *intPtr)
        {
            compticket = assignedtix;
            assignedtix = NULL;
        }
        else
        {
            prev = assignedtix;
            assignedtix = (*assignedtix).next;
        }
    }
    if (compticket == NULL)
    {
        printf("we could not find the ticket corresponding to your number\n");
    }
    else
    {
        if (prev == NULL)
        {
            assignedtix = (*compticket).next;
        }
        else
        {
            (*prev).next = (*compticket).next;
        }
        strcpy((*compticket).status, "completed");
        if (completedtix == NULL)
        {
            completedtix = compticket;
            (*completedtix).next = NULL;
            completedtixcopy = completedtix;
        }
        else
        {
            completedtixcopy = completedtix;
            while ((*completedtix).next != NULL)
            {
                completedtix = (*completedtix).next;
            }
            (*completedtix).next = compticket;
            (*compticket).next = NULL;
        }
    }

    return completedtixcopy;
}

/* this function takes pointers to the heads of both the new and assigned
ticket lists, and returns to us th head of the updated ticket list.

preconditions: assignedtix and new are valid pointers, can be null
postconditions: the assignedtix head that is returned mus be valid*/
ticket_t *assigntix(ticket_t *new, ticket_t *assignedtix)
{
    printf("you have entered the the assign ticket function\n");
    ticket_t *assignedtixcopy = (ticket_t *)malloc(sizeof(ticket_t *));
    if (new == NULL)
    {
        printf("there are no new nodes. you have to make a new node\n");
    }
    else
    {
        strcpy((*new).status, "assigned");
        for (int i = 0; i < 11; i++)
        {
            (*new).technicianname[i] = '\0'; /*this resets the technician
             character array to null chars to get rid of unassigned*/
        }
        char ch;
        int i = 0;
        printf("what is the technician's name:");
        {
            while ((ch = getchar()) != '\n')
            {
                (*new).technicianname[i] = ch; // assigning the technician to the first ticket of the new list;
                i++;
            }
        }
    }
    if (assignedtix == NULL)
    {
        assignedtix = new;          // the first ticket in the assigned ticket list is thw
        (*assignedtix).next = NULL; // setting the end of the assigned tickets list
        new = (*new).next;          // sets the head of the newtickets list to be the next new ticket;
        assignedtixcopy = assignedtix;
    }
    else
    {
        assignedtixcopy = assignedtix;
        while ((*assignedtix).next != NULL)
        {
            assignedtix = (*assignedtix).next;
        }
        (*assignedtix).next = new;
        new = (*new).next;
        (*(*assignedtix).next).next = NULL;
    }
    return assignedtixcopy;
}

/* this function takes a pointer to the head of the new tickets list,
and returns the newlist with modifications based on the new ticket you made

preconditions: newList is a valid pointers, can be null
postconditions: the newList head that is returned mus be valid, shouldn't be null*/
ticket_t *makenewtix(ticket_t *newlist)
{
    printf("you have entered the make-new-ticet procedure\n");
    ticket_t *newTicket = malloc(sizeof(ticket_t) * 1); // alllocating space for a new node
    ticket_t *newlisthead = NULL;
    if (newlist == NULL)
    {
        (*newTicket).ticketnum = 1; // if the list is empty, this is the first ticket.
        newlisthead = newTicket;
        printf("this new ticket has been assigned the number %d\n", (*newTicket).ticketnum);
    }
    else
    {
        newlisthead = newlist;
        while ((*newlist).next != NULL) // loop to find the last ticket
        {
            newlist = (*newlist).next;
        }
        (*newTicket).ticketnum = (*newlist).ticketnum + 1;
        printf("this new ticket has been assigned the number %d\n", (*newTicket).ticketnum);
        (*newlist).next = newTicket; // the ticket is set as the last thing in the list
        (*newTicket).next = NULL;    // the next is set to be null
    }
    strcpy((*newTicket).technicianname, "unassigned");
    printf("what is the error code:");
    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n')
    {
        (*newTicket).issuecode[i] = ch;
        i++;
    }
    (*newTicket).issuecode[i] = '\0';
    printf("what is the company code:");
    char chh;
    int x = 0;
    while ((chh = getchar()) != '\n')
    {
        (*newTicket).companyident[x] = chh;
        x++;
    }
    (*newTicket).companyident[x] = '\0';
    strcpy((*newTicket).status, "New");
    return newlisthead; // returns the head of the list
}

/* prompts the user for their input, and returns their input integer.
pre and postconditions: none*/
int printchoicemenu(void)
{
    int *choiceptr = (int *)malloc(sizeof(int) * 1);
    printf("this procedure takes a number 0 - 7 corresponding to an action with our tickets\n");
    printf("1: create a new ticket\n");
    printf("2: assigning a ticket\n");
    printf("3: complete a ticket\n");
    printf("4: print the new ticket list\n");
    printf("5: print the assigned ticket list\n");
    printf("6: print the completed ticket list\n");
    printf("what would you like to do now:");
    scanf("%d", choiceptr);
    return *choiceptr;
}

/*this function takes the pointer to the head of a list, and prints it out, from beginning to end
preconditions: none
postconditiions: none*/
void printList(ticket_t *list)
{
    printf("now printing the list\n");
    while (list != NULL)
    {
        printf("number is %d\n", (*list).ticketnum);
        printf("company is %s\n", (*list).companyident);
        printf("issue code is %s\n", (*list).issuecode);
        printf("status is %s\n", (*list).status);
        printf("technician name is %s\n", (*list).technicianname);
        printf("moving to next node\n");
        list = (*list).next;
    }
}

int main(void)
{
    ticket_t *newtickets = NULL;
    ticket_t *assignedtickets = NULL;
    ticket_t *completedtickets = NULL;

    int numtickets = 0;
    newtickets = makenewtix(newtickets);
    assignedtickets = assigntix(newtickets, assignedtickets);
    completedtickets = completedtix(assignedtickets, completedtickets);

    printList(completedtickets);
    return 0;
}