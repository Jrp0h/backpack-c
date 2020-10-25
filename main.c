#include "include/backpack.h"

#include <stdio.h>

int main() {
  // Allocate and instanciate backpack
  backpack_T* backpack = backpack_new(60, 50);

  // Allocate and instanciate items
  item_T* anorak = item_new(0, "Anorak", 1.3f, 4.0f); 
  item_T* byxor = item_new(1, "byxor", 0.78f, 0.87f); 
  item_T* citronpress = item_new(2, "Citronpress", 0.45f, 0.9f); 
  item_T* damsadel = item_new(3, "Damsadel", 22.0f, 40.0f); 
  item_T* espressokopp = item_new(4, "Espressokopp", 0.08f, 0.1f); 
  item_T* fru = item_new(5, "Frugan", 65.0f, 65.0f); 
  item_T* lightbulb = item_new(6, "Glödlampa", 0.07f, 0.08f); 
  item_T* horse = item_new(7, "Häst", 300.0f, 300.0f); 
  item_T* ismaskin = item_new(8, "Ismaskin", 4.0f, 12.0f); 

  // try adding items
  backpack_add_item(backpack, horse);
  backpack_add_item(backpack, fru);
  backpack_add_item(backpack, byxor);
  backpack_add_item(backpack, byxor);
  backpack_add_item(backpack, damsadel);
  backpack_add_item(backpack, espressokopp);

  backpack_remove_item(backpack, byxor, 2);

  // Print out all items
  backpack_print_items(backpack);

  // Free memory used by backpack
  backpack_destroy(backpack);

  // Free all memory used by items 
  item_destroy(anorak);
  item_destroy(byxor);
  item_destroy(citronpress);
  item_destroy(damsadel);
  item_destroy(espressokopp);
  item_destroy(fru);
  item_destroy(lightbulb);
  item_destroy(horse);
  item_destroy(ismaskin);
}

