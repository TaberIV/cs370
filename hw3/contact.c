/**********************************************************
 * Name         : contact.c
 * Authors      : E. Taber McFarlin, Chris Byrne, and Luke L...
 * Version      : 1.0
 * Date         : February  14, 2019
 * Description  : Solution to HackerRank Contacts
 * https://www.hackerrank.com/challenges/contacts/problem
 **********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_LENGTH 26
#define OPERATION_BUF_SIZE 7 /* Large enough to cover the word 'search' and '\0' */
#define NAME_BUF_SIZE 22

// Define trie
typedef struct node
{
  int num_children;
  struct node *children[ALPHABET_LENGTH + 1];
} trie_node;

//creates a new trie
trie_node *trie_new()
{
  trie_node *trie = malloc(sizeof(trie_node));

  trie->num_children = 0;
  
  for (int i = 0; i <= ALPHABET_LENGTH; i++)
  {
    trie->children[i] = NULL;
  }

  return trie;
}

//frees the trie from memory
void trie_free(trie_node *trie)
{
  for (int i = 0; i <= ALPHABET_LENGTH; i++)
  {
    if (trie->children[i] != NULL)
    {
      trie_free(trie->children[i]);
    }
  }

  free(trie);
}

// Trie operations
// Add name to trie
int add(char name[], int index, trie_node *trie)
{
  trie->num_children += 1;

  if (name[index] == '\0')
  {
    trie->children[ALPHABET_LENGTH] = trie_new();
    return 1;
  }
  else
  {
    int child = name[index] - 'a';
    //creates a new trie if there does not exist a child at the index
    if (trie->children[child] == NULL)
    {
      trie->children[child] = trie_new();
    }

    return add(name, index + 1, trie->children[child]);
  }
}

// Find number of names that begin with the partial entry
int find(char partial[], int index, trie_node *trie)
{
  if (partial[index] == '\0')
  {
    return trie->num_children;
  }
  else
  {
    int child = partial[index] - 'a';
    //Checks if the letter at the current index is correct
    if (trie->children[child] == NULL)
    {
      return 0;
    }
    else
    {
      return find(partial, index + 1, trie->children[child]);
    }
  }
}

// Find if exact name has been added
bool search(char name[], int index, trie_node *trie)
{
  if (name[index] == '\0')
  {
    return trie->children[ALPHABET_LENGTH] != NULL;
  }
  else
  {
    // Checks if the letter at the current index is correct
    int child = name[index] - 'a';

    if (trie->children[child] == NULL)
    {
      return false;
    }
    else
    {
      return search(name, index + 1, trie->children[child]);
    }
  }

  return 1;
}

// main
int main()
{
  // Create trie
  trie_node *trie = trie_new();

  // Process input
  char operation[OPERATION_BUF_SIZE];
  char arg[NAME_BUF_SIZE];
  int n;
  scanf("%d", &n);

  while (n > 0)
  {
    scanf("%s %s", operation, arg);

    if (strcmp(operation, "add") == 0)
    {
      add(arg, 0, trie);
    }
    else if (strcmp(operation, "find") == 0)
    {
      int found = find(arg, 0, trie);
      printf("%d\n", found);
    }
    else if (strcmp(operation, "search") == 0)
    {
      bool found = search(arg, 0, trie);
      printf(found ? "yes\n" : "no\n");
    }
    else
    {
      printf("Invalid Input %s\n", operation);
    }

    n--;
  }

  // Free data structures
  trie_free(trie);

  return 1;
}
