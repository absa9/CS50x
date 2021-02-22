/* Implements a dictionary's functionality
// with Hash-Tabel
*/

#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"


// define struct node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
// hash table size = 2^16
const unsigned int N = 65536;

//counter to count the words in the dictionary
int words = 0;

// Hash table
node *hashtable[N];

//Hash Function
/**
* https://www.reddit.com/r/cs50/commentsTop/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn/
**/
int hash(const char *word)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;
}


//Returns true if word is in dictionary else false.

bool check(const char *word)
{
    // convert words to lowercase
    //TODO: change from length to length of word
    int len = strlen(word);
    char lc_word[len + 1];
    for (int i = 0; i < len; i++)
    {
        lc_word[i] = tolower(word[i]);
    }
    lc_word[len] = '\0';

    int bucket = hash(lc_word);
    // set head to start of lined list
    node *head = hashtable[bucket];
    // traverse list
    while (head != NULL)
    {
        // check node's word to see if it is target word, ignoring case
        if (strcasecmp(head->word, lc_word) != 0)
        {
            head = head->next;
        }
        else
            return true;
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    //open the dictionary file
    FILE *dic = fopen(dictionary, "r");
    //check that file opens correctly
    if (dic == NULL)
    {
        fprintf(stderr, "Cound not open %s.\n", dictionary);
        return false;
    }

    char buffer[LENGTH + 1];

    while (fscanf(dic, "%s", buffer) != EOF)
    {
        // create a temporary node
        node *temp = malloc(sizeof(node));

        strncpy(temp->word, buffer, sizeof(buffer));

        // implement hash function to get the index
        int index = hash(buffer);

        // if the corresponding index in hashtable is empty, assign it to the temp node
        if (hashtable[index] == NULL)
            hashtable[index] = temp;

        // else append temp to the start of the linked list
        else
        {
            temp->next = hashtable[index];
            hashtable[index] = temp;
        }
        words ++;
    }
    fclose(dic);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return words;
}

void rem(node *head)
{
    if (head->next != NULL)
    {
        rem(head->next);
    }
    free(head);
}


/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (hashtable[i] != NULL)
        {
            rem(hashtable[i]);
        }
    }
    return true;
}