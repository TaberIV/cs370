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

typedef struct node
{
  int num_children;
  struct node *children[ALPHABET_LENGTH + 1];
} trie_node;

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

    if (trie->children[child] == 0)
    {
      trie->children[child] = trie_new();
    }

    return add(name, index + 1, trie->children[child]);
  }
}

int find(char partial[], int index, trie_node *trie)
{
  if (partial[index] == '\0')
  {
    return trie->num_children;
  }
  else
  {
    int child = partial[index] - 'a';

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

bool search(char name[], int index, trie_node *trie)
{
  if (name[index] == '\0')
  {
    return trie->children[ALPHABET_LENGTH] != NULL;
  }
  else
  {
    int child = name[index] - 'a';

    if (trie->children[child] == NULL)
    {
      return false;
    }
    else
    {
      return find(name, index + 1, trie->children[child]);
    }
  }

  return 1;
}

int main()
{
  char operation[OPERATION_BUF_SIZE];
  char arg[NAME_BUF_SIZE];

  trie_node *trie = trie_new();

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
      printf(search(arg, 0, trie) ? "yes\n" : "no\n");
    }
    else
    {
      printf("Invalid Input %s\n", operation);
    }

    n--;
  }

  trie_free(trie);

  return 1;
}
