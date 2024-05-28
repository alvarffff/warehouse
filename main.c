#include <stdio.h>
#include <stdlib.h>
#include "warehouse.h"

int main()
{
    printf("Hola\n");
    Warehouse warehouse;

    warehouse_init(&warehouse, 10, 10);
    warehouse_print(warehouse);
    warehouse_add_item(&warehouse,2,2, 4);
    warehouse_print(warehouse);

    
    return 0;
}


