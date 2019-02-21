/**************************************************************
 * Name         : hashit.c
 * Authors      : E. Taber McFarlin, Chris Byrne, and Luke L
 * Version      : 1.0
 * Date         : February  21, 2019
 * Description  : Solution to SPOJ HASHIT
 * http://www.spoj.com/problems/HASHIT/
 **************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 101
#define KEY_LEN     15
#define OP_LEN       3

typedef struct {
    char* keys[TABLE_SIZE];
    int num_keys;
} hash_set;

void clear_table(hash_set *set) {

}

int hash(char *key) {
  int hashVal = 0;

  for (int i = 0; key[i] != '\0'; i++) {
    hashVal = key[i] * (i + 1);
  }

  return (19 * hashVal) % TABLE_SIZE;
}

int insert_key(hash_set *set, char *key) {

  return 0;
}

int delete_key(hash_set *set, char *key) {
  
  return 0;
}

void display_keys(hash_set *set) {

}

int main() {
  // Create hash table
  hash_set *table = malloc(sizeof(hash_set));

  // Input
  char *input = malloc((OP_LEN + KEY_LEN) * sizeof(char));

  int t;
  for (scanf("%d", &t); t > 0; t--) {
    int n;
    for (scanf("%d", &n); n > 0; n--) {
      scanf("%s", input);

      if (input[0] == 'A') {
        insert_key(table, input + OP_LEN + 1);
      } else if (input[0] = 'D') {
        insert_key(table, input + OP_LEN + 1);
      }
    }
  }
}