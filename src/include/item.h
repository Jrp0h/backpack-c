#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>

typedef struct ITEM_STRUCT {
  int id;
  char* name;
  float weight;
  float volume;
} item_T;

item_T* item_new(int id, char* name, float weight, float volume);
void item_destroy(item_T* item);

float* item_weight(item_T* item);
float* item_volume(item_T* item);

char** item_name(item_T* item);

bool item_compare(item_T* item1, item_T* item2);

void item_print(item_T* item1);

#endif
