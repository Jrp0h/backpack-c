#include "include/backpack.h"
#include "include/itemcount.h"
#include "include/item.h"

#include <stdlib.h>
#include <stdio.h>

backpack_T* backpack_new(float max_weight, float max_volume)
{
  backpack_T* bp = malloc(sizeof(struct BACKPACK_STRUCT));

  if(bp == NULL)
  {
    fprintf(stderr, "Failed to allocate memory for backpack\n");
    exit(1);
    return NULL;
  }

  bp->max_volume = max_volume;
  bp->max_weight = max_weight;

  bp->current_volume = 0;
  bp->current_weight = 0;

  bp->items = vector_new(10);

  return bp;
}

void backpack_destroy(backpack_T* backpack) {
  vector_destroy(backpack->items);
  free(backpack); 
}

bool backpack_add_item(backpack_T* backpack, item_T* item) {

  // check and see that the volume with the new object isn't too big
  if(backpack->current_volume + item->volume > backpack->max_volume)
    return false;

  // check and see that the weight with the new object isn't too big
  if(backpack->current_weight + item->weight > backpack->max_weight)
    return false;

  // Go over all items and see if it already exists
  for(int i = 0; i < vector_size(backpack->items); i++)
  {
    item_count_T* item_count = (item_count_T*)vector_at(backpack->items, i);
    item_T* existing_item = item_count_get_item(item_count);

    // are they the same (same id)
    // if they are, the and one
    // and add correct weight and volume
    // to the backpack
    if(item_compare(existing_item, item))
    {
      item_count_add(item_count, 1);

      backpack->current_volume += existing_item->volume;
      backpack->current_weight += existing_item->weight;

      return true;
    }
  }
  
  // If this code runs it means that the
  // item doesn't exist in the backpack
  // add it to the backpack and update
  // weight and volume
  item_count_T* new_item = item_count_new(item);
  vector_push(backpack->items, new_item);

  backpack->current_volume += item->volume;
  backpack->current_weight += item->weight;

  return true;
}

void backpack_remove_item(backpack_T* backpack, item_T* item, int amount) { 

  // Go over all items to see if it exists
  for(int i = 0; i < vector_size(backpack->items); i++)
  {
    item_count_T* item_count = (item_count_T*)vector_at(backpack->items, i);
    item_T* existing_item = item_count_get_item(item_count);

    // are they the same (same id)
    if(item_compare(existing_item, item))
    {
      int count = item_count_get_count(item_count);
      item_count_remove(item_count, amount);

      // if there are none left, remove it from the list
      if(item_count_get_count(item_count) <= 0)
        vector_remove_at(backpack->items, i);

      // go over the amount of items removed
      // add decrease backpacks current_volume
      // and current_weight by the weight
      // of the item. if there were fewer items
      // than removed, the only remove the amount
      // that there were
      for(int i = 0; i < amount && i < count; i++)
      {
        backpack->current_volume -= existing_item->volume;
        backpack->current_weight -= existing_item->weight;
      }

      return;
    }
  }
}

float backpack_get_current_weight(backpack_T* backpack) {
  return backpack->current_weight;
}

float backpack_get_current_volume(backpack_T* backpack) {
  return backpack->current_volume;
}

void backpack_print_items(backpack_T* backpack) {
  printf("Total Weight: %.2f\nTotal Volume: %.2f\n", backpack->current_weight, backpack->current_weight);

  for(int i = 0; i < vector_size(backpack->items); i++)
  {
    item_count_print_item(vector_at(backpack->items, i));
  }
}

void backpack_set_max_weight(backpack_T* backpack, float max) {
  backpack->max_weight = max;
}
void backpack_set_max_volume(backpack_T* backpack, float max) {
  backpack->max_volume = max;
}

float backpack_get_max_weight(backpack_T* backpack){ 
  return backpack->max_weight;
}
float backpack_get_max_volume(backpack_T* backpack) {
  return backpack->max_volume;
}
