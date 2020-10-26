#ifndef BACKPACK_H
#define BACKPACK_H

#include <stdbool.h>

#include "vector.h"
#include "item.h"
#include "itemcount.h"

typedef struct BACKPACK_STRUCT {
  float max_weight;
  float max_volume;

  float current_weight;
  float current_volume;

  vector_T* items;
} backpack_T;

backpack_T* backpack_new(float max_weight, float max_volume);
void backpack_destroy(backpack_T* backpack);

bool backpack_add_item(backpack_T* backpack, item_T* item);
bool backpack_remove_item(backpack_T* backpack, item_T* item, int amount);

float backpack_get_current_weight(backpack_T* backpack);
float backpack_get_current_volume(backpack_T* backpack);

void backpack_set_max_weight(backpack_T* backpack, float max);
void backpack_set_max_volume(backpack_T* backpack, float max);

float backpack_get_max_weight(backpack_T* backpack);
float backpack_get_max_volume(backpack_T* backpack);

void backpack_print_items(backpack_T* backpack);
#endif
