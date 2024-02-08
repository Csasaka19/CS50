// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 26 * 26 * 26 * 26 * 26 + 1;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Check if the word is in the dictionary
    // Case insensitive
    // Return true if the word is in the dictionary
    // Hash the word
    int index = hash(word);
    // Traverse the linked list at the index
    for (node *tmp = table[index]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

unsigned int hash(const char *word)
{
    // If same input is given to the hash function, it should return the same output
    // The hash function should be deterministic
    // Larger N function will be more efficient as more buckets means less collision
    // Index = (sum of ASCII values of the word) % N 
    int index = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index += tolower(word[i]);
    }
    return index % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        printf("Unable to open file");
        return 1;
    }
    // Allocate memory
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Unable to allocate memory");
        return 1;
    }

    // Read words within the dictionary file
    while (fscanf(source, "%s", n->word) != EOF)
    {
        //Hash the word
        int index = hash(n->word);
        // Insert word to the hash table
        n->next = table[index];
        table[index] = n;
    }
    //close the dictionary file
    fclose(source);
    // Return true if successful
    // Return false if unsuccessful
    if (source == NULL)
    {
        return false;
    }
    return true;
}

unsigned int size(void)
{
    // Each time size is called, iterate through the words in the hash table to count them up. Return that count.
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (node *tmp = table[i]; tmp != NULL; tmp = tmp->next)
        {
            count++;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *tmp = NULL;
    // Iterate through the words in the hash table and free them
    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i];
        while (tmp != NULL)
        {
            node *temp = tmp;
            tmp = tmp->next;
            free(temp);
        }
    }
    if (tmp == NULL)
    {
        return true;
    }
    return false;
}
