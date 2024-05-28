#include "warehouse.h"

void load_warehouse()
{

}

void warehouse_init(Warehouse *warehouse, int height, int width)
{
    warehouse->height = height;
    warehouse->width = width;
    // Asignar memoria para las filas (punteros a las columnas)
    warehouse->cells = (int **)calloc(height, sizeof(int *));
    if (warehouse->cells == NULL) {
        perror("Error al asignar memoria para las filas");
        exit(EXIT_FAILURE);
    }

    // Asignar memoria para cada fila (las columnas)
    for (int i = 0; i < height; i++) {
        warehouse->cells[i] = (int *)calloc(width, sizeof(int));
        if (warehouse->cells[i] == NULL) {
            perror("Error al asignar memoria para las columnas");
            // Liberar memoria asignada hasta ahora para evitar fugas
            for (int j = 0; j < i; j++) {
                free(warehouse->cells[j]);
            }
            free(warehouse->cells);
            exit(EXIT_FAILURE);
        }
    }
}

int warehouse_add_item(Warehouse *warehouse, int x, int y, int id)
{   
    if(warehouse->cells[x][y] == 0)
    {
        warehouse->cells[x][y] = id;
        return 0;
    }
    return -1; 
}

void warehouse_print(Warehouse warehouse)
{   
    for (int x = 0; x < warehouse.width; x++)
    {  
        for(int y = 0; y < warehouse.height; y++)
        {
            printf("%d ",warehouse.cells[x][y]);
        }
        printf("\n");
    }
     printf("\n\n");
}
