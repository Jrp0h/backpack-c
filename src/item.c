#include "include/item.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

item_T* item_new(int id, char* name, float weight, float volume)
{
  item_T* item = malloc(sizeof(struct ITEM_STRUCT));

  if(item == NULL)
  {
    fprintf(stderr, "Failed to allocate memory\n");
    exit(1);
    return NULL;
  }

  item->id = id;
  item->name = name;
  item->weight = weight;
  item->volume = volume;

  return item;
}

void item_destroy(item_T* item)
{
  free(item);
}

float* item_weight(item_T* item)
{
  return &item->weight;
}

float* item_volume(item_T* item)
{
  return &item->volume;
}

char** item_name(item_T* item)
{
  return &item->name;
}

bool item_compare(item_T* item1, item_T* item2)
{
  return item1->id == item2->id;
}

void item_print(item_T* item) {
  printf("Id: %d\n\tName: %s \n\tWeight: %.2fkg\n\tVolume: %.2fL\n", item->id, item->name, item->weight, item->volume);
}
