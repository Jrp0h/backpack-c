#ifndef ITEM_COUNT_H
#define ITEM_COUNT_H

#include "item.h"

typedef struct ITEM_COUNT_STRUCT {
  int count;
  item_T* item;
} item_count_T;

item_count_T* item_count_new(item_T* item);
void item_count_destroy(item_count_T* item_count);

item_T* item_count_get_item(item_count_T* item_count);

int item_count_get_count(item_count_T* item_count);

void item_count_add(item_count_T* item_count, int amount);
void item_count_remove(item_count_T* item_count, int amount);

void item_count_print_item(item_count_T* item_count);
#endif
