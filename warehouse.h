#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Warehouse{
    int height;
    int width;
    int **cells; 
} Warehouse;

void warehouse_init(Warehouse *warehouse, int height, int width);
int warehouse_add_item(Warehouse *warehouse, int x, int y, int id);
void warehouse_print(Warehouse warehouse);

#endif