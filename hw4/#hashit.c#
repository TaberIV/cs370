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
#define KEY_LEN 16
#define OP_LEN 4

typedef struct {
  char *keys[TABLE_SIZE];
  int num_keys;
} hash_set;

hash_set *new_table() { return calloc(1, sizeof(hash_set)); }

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
    hash_val += key[i] * (i + 1);
  }

  return (19 * hash_val) % TABLE_SIZE;
}

int insert_key(hash_set *set, char *key) {
  // Get index
  int hash_val = hash(key);
  int index = hash_val;

  // Collision handling
  bool index_found = false;
  bool copy_found = false;
  for (int j = 0; j < 20; j++) {
    int pos_index = (hash_val + j * j + 23 * j) % TABLE_SIZE;

    if (!index_found && !set->keys[pos_index]) {
      index_found = true;
      index = pos_index;
    } else if (set->keys[pos_index] && strcmp(set->keys[pos_index], key) == 0) {
      copy_found = true;
    }
  }

  // Unhandled collision or repeated keys
  if (copy_found || !index_found) {
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

  // Collision handling
  for (int j = 0; j < 20; j++) {
    int index = (hash_val + j * j + 23 * j) % TABLE_SIZE;

    if (set->keys[index] && strcmp(set->keys[index], key) == 0) {
      // Delete key
      free(set->keys[index]);
      set->keys[index] = NULL;
      set->num_keys--;

      return 1;
    }
  }

  // Unhandled collision or key not found
  return 0;
}

void display_keys(hash_set *set) {
  printf("%d\n", set->num_keys);

  for (int i = 0; i < TABLE_SIZE; i++) {
    if (set->keys[i]) {
      printf("%d:%s\n", i, set->keys[i]);
    }
  }
}

int main(void) {
  // Create hash table
  hash_set *table = new_table();

  // Input
  char *input = malloc((OP_LEN + KEY_LEN) * sizeof(char));

  int t;
  for (scanf("%d", &t); t > 0; t--) {

    int n;
    for (scanf("%d", &n); n > 0; n--) {
      scanf("%s", input);

      if (input[0] == 'A') {
        insert_key(table, input + OP_LEN);
      } else if (input[0] = 'D') {
        delete_key(table, input + OP_LEN);
      }
    }

    display_keys(table);
    clear_table(table);
  }
  free(table);
  free(input);

  return 0;
}