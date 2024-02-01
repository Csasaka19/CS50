#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node* next;
} node ;

int main(int argc, char const *argv[]){
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // Free memory
            return 1;
        }
        n->number = number;
        n->next = list;
        list = n;
    }
    
    // Printing the values of the nodes in the linked list
    node *tmp = list;
    while(tmp != NULL){
        // Values will be printed in reverse order since the new node is always added to the beginning of the list
        printf("%i\n", tmp->number);
        tmp = tmp->next;
    }
    return 0;
}