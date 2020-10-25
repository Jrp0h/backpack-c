#include "include/itemcount.h"

#include <stdlib.h>
#include <stdio.h>

item_count_T* item_count_new(item_T* item){
  item_count_T* item_count = malloc(sizeof(struct ITEM_COUNT_STRUCT));

  if(item_count == NULL)
  {
    fprintf(stderr, "Failed to allocate memory for item_count\n");
    exit(1);
    return NULL;
  }

  item_count->item = item;
  item_count->count = 1;

  return item_count;
}

void item_count_destroy(item_count_T* item_count) {
  free(item_count);
}

item_T* item_count_get_item(item_count_T* item_count){
  return item_count->item;
}

int item_count_get_count(item_count_T* item_count) {
  return item_count->count;
}

void item_count_add(item_count_T* item_count, int amount){
  item_count->count += amount;
}

void item_count_remove(item_count_T* item_count, int amount) {
  item_count->count -= amount;
}

void item_count_print_item(item_count_T* item_count) {
  printf("%d items of ", item_count->count);
  item_print(item_count->item);
}
