#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Warehouse{
    int height;
    int width;
    int **cells; 
} Warehouse;

typedef struct Object{
    int id;
    int x;
    int y;
} Object ;

Warehouse warehouse_load(char *filename);
void warehouse_init(Warehouse *warehouse, int height, int width);
int warehouse_add_item(Warehouse *warehouse, int x, int y, int id);
void warehouse_print(Warehouse warehouse);

#endif