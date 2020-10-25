# README

## Compile and run

First run

```bash
./cmake.sh
```

then when you want to build and run

```bash
./br.sh
```

## Documentation

### Backpack

Create backpack

```c
backpack_T* backpack = backpack_new(float max_weight, float max_volume);
```

Destroy backpack

```c
backpack_destroy(backpack_T* backpack);
```

Add item to backpack

```c
bool couldAdd = backpack_add_item(backpack_T* backpack, item_T* item);
```

Remove item from backpack

```c
backpack_remove_item(backpack_T* backpack, item_T* item, int amount);
```

Get weight of backpack

```c
float weight = backpack_get_current_weight(backpack_T* backpack);
```

Get volume of backpack

```c
float volume = backpack_get_current_volume(backpack_T* backpack);
```

Get max weight of backpack

```c
float maxWeight = backpack_get_max_weight(backpack_T* backpack);
```

Get max volume of backpack

```c
float maxVolume = backpack_get_max_volume(backpack_T* backpack);
```

Set max weight of backpack

```c
backpack_set_max_weight(backpack_T* backpack, float max);
```

Set max volume of backpack

```c
backpack_set_max_volume(backpack_T* backpack, float max);
```

Print out all items

```c
void backpack_print_items(backpack_T* backpack);
```

### Item

Create item

```c
item_T* item = item_new(int id, char* name, float weight, float volume);
```

Destroy item

```c
item_destroy(item_T* item);
```

Print item

```c
item_print(item_T* item);
```
