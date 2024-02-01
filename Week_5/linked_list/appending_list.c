#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int number;
    struct node *next;
}node;

int main(int argc, char const *argv[])
{
    // Create a linked list that appends nodes to the end of the list
    node *list = NULL;
    node *tmp = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]); // Fix: Convert the command line argument to an integer correctly
        node *n = malloc(sizeof(node));
        if (n ==NULL)
        {
            // Free memory
            return 1;
        }
        n->number = number;
        n->next = NULL;

        // Append the node to the end of the list
        if (list == NULL)
        {
            list = n;
            tmp =list;
        }
        else
        {
            tmp->next = n;
            tmp = tmp->next;
        }
    }

    // Printing the values of the nodes in the linked list
    tmp = list;
    while(tmp != NULL)
    {
        printf("%i\n", tmp->number);
        // Prevent memory leaks
        node *nextNode = tmp->next;
        free(tmp);
        tmp = nextNode;
    }
    return 0;
}