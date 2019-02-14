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
#include <stdbool.h>
#include <string.h>

#define ALPHABET_LENGTH    26
#define OPERATION_BUF_SIZE  7 /* Large enough to cover the word 'search' and '\0' */
#define NAME_BUF_SIZE      22

typedef struct node
{
  int num_children;
  struct node *children[ALPHABET_LENGTH + 1];
} trie_node;

trie_node *new_trie()
{
  trie_node *trie = malloc(sizeof(trie_node));

  return trie;
}

int add(char name[], int index, trie_node *trie)
{
  trie->num_children += 1;

  if (name[index] == '\0')
  {
    trie->children[ALPHABET_LENGTH] = new_trie();
    return 1;
  }
  else
  {
    int child = name[index] - 'a';

    if (trie->children[child] == 0)
    {
      trie->children[child] = new_trie();
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

    if (trie->children[child] == 0)
    {
      return 0;
    }
    else
    {
      return find(partial, index + 1, trie->children[child]);
    }
  }
}

int search(char name[], int index, trie_node *trie)
{

  return 1;
}

int main()
{
  char operation[OPERATION_BUF_SIZE];
  char arg[NAME_BUF_SIZE];

  trie_node *trie = new_trie();

  int n = getchar() - '0';

  while (n > 0)
  {
    scanf("%s %s", operation, arg);

    if (strcmp(operation, "add") == 0)
    {
      add(arg, 0, trie);
    }
    else if (strcmp(operation, "find") == 0)
    {
      printf("%d\n", find(arg, 0, trie));
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

  return 1;
}
