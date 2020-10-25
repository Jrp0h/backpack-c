#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>

typedef struct VECTOR_STRUCT {
  void** data;
  int capacity;
  int current_index;
} vector_T;


vector_T* vector_new(int size);
void vector_destroy(vector_T* vector);

void vector_resize(vector_T* vector, int new_size);

int vector_size(vector_T* vector);
int vector_capacity(vector_T* vector);

void* vector_at(vector_T* vector, int index);
void vector_remove_at(vector_T* vector, int index);

void vector_push(vector_T* vector, void* value);

void* vector_pop(vector_T* vector);
void* vector_peek(vector_T* vector);

bool vector_need_realloc(vector_T* vector);
bool vector_is_empty(vector_T* vector);

#endif
