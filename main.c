#include <stdio.h>
#include <stdlib.h>
#include "warehouse.h"
#include "object.h"

extern Object object_list[100];

int main()
{
    Warehouse warehouse;

    warehouse = warehouse_load("map_w0.txt");
    //warehouse_init(&warehouse, 10, 10);
    warehouse_print(warehouse);
    warehouse_add_item(&warehouse,2,2,4);
    warehouse_print(warehouse);
    return 0;
}


