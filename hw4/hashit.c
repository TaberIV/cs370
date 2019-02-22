/**************************************************************
 * Name         : hashit.c
 * Authors      : E. Taber McFarlin, Chris Byrne, and Luke L
 * Version      : 1.0
 * Date         : February  21, 2019
 * Description  : Solution to SPOJ HASHIT
 * http://www.spoj.com/problems/HASHIT/
 **************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101
#define KEY_LEN 15
#define OP_LEN 3

typedef struct {
  char *keys[TABLE_SIZE];
  int num_keys;
} hash_set;

hash_set *new_table() {
  hash_set *set = malloc(sizeof(hash_set));

  for (int i = 0; i < TABLE_SIZE; i++) {
    set->keys[i] = NULL;
  }

  set->num_keys = 0;
}

void clear_table(hash_set *set) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (set->keys[i]) {
      free(set->keys[i]);
    }

    set->keys[i] = NULL;
  }

  set->num_keys = 0;
}

int hash(char *key) {
  int hash_val = 0;

  for (int i = 0; key[i] != '\0'; i++) {
    hash_val = key[i] * (i + 1);
  }

  return (19 * hash_val) % TABLE_SIZE;
}

int insert_key(hash_set *set, char *key) {
  // Get index
  int hash_val = hash(key);
  int index = hash_val;

  // Collision handling
  int j = 1;
  while (set->keys[index] && j < 20) {
    index = (hash_val + j * j + 23 * j) % TABLE_SIZE;
    j++;
  }

  // Unhandled collision
  if (set->keys[index]) {
    return 0;
  }

  // Insert key
  set->keys[index] = strcpy(malloc(sizeof(char) * KEY_LEN), key);
  set->num_keys++;

  return 1;
}

int delete_key(hash_set *set, char *key) {
  // Get index
  int hash_val = hash(key);
  int index = hash_val;

  // Collision handling
  int j = 1;
  while (strcmp(set->keys[index], key) != 0 && j < 20) {
    index = (hash_val + j * j + 23 * j) % TABLE_SIZE;
    j++;
  }

  // Unhandled collision
  if (strcmp(set->keys[index], key) != 0) {
    return 0;
  }

  // Delete key
  free(set->keys[index]);
  set->keys[index] = NULL;
  set->num_keys--;

  return 1;
}

void display_keys(hash_set *set) {
  printf("%d\n", set->num_keys);

  for (int i = 0; i < TABLE_SIZE; i++) {
    if (set->keys[i]) {
      printf("%d:%s\n", i, set->keys[i]);
    }
  }

  printf("\n");
}

int main() {
  // Create hash table
  hash_set *table = new_table();

  // Input
  char *input = malloc((OP_LEN + KEY_LEN) * sizeof(char));

  int t;
  for (scanf("%d", &t); t > 0; t--) {
    clear_table(table);

    int n;
    for (scanf("%d", &n); n > 0; n--) {
      scanf("%s", input);

      if (input[0] == 'A') {
        insert_key(table, input + OP_LEN + 1);
      } else if (input[0] = 'D') {
        delete_key(table, input + OP_LEN + 1);
      }
    }

    display_keys(table);
  }

  free(input);

  clear_table(table);
  free(table);

  return 0;
}