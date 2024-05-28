#include "warehouse.h"

Warehouse warehouse_load(char *filename)
{
    FILE *fp = fopen(filename, "r");
    Warehouse w;
    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
    }

    // read one character at a time and
    // display it to the output
    char ch;
    Object object_list[100]; //TODO change fixed lenght
    int count_objects = 0;
    int count_x = 0;
    int count_y = 0;
    while ((ch = fgetc(fp)) != EOF)
    {
        if(ch == '\n'){
            count_y++;
            count_x = 0;
        }
        else
        {
            
             
            if(ch != '0' && ch != '\r')
            {   
                //printf(" ID: %d, Count_x %d, count_y %d \n", ch -'0' , count_x, count_y);
                object_list[count_objects].id = ch -'0' ;
                object_list[count_objects].x = count_x;
                object_list[count_objects].y = count_y;
                count_objects++;
            }
            count_x++;
        }
    
        putchar(ch);   
    }

    warehouse_init(&w,count_x, count_y + 1);
    
    for (int i = 0; i < count_objects; i++)
    {   
        //printf ("X %d, Y %d, ID %d \n", object_list[i].x, object_list[i].y, object_list[i].id);
        warehouse_add_item(&w, object_list[i].x, object_list[i].y, object_list[i].id);
    }
    // close the file
    fclose(fp);
    return w;
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
    printf("\n\n");
    for (int x = 0; x < warehouse.width; x++)
    {  
        for(int y = 0; y < warehouse.height; y++)
        {
            printf("%d",warehouse.cells[y][x]);
        }
        printf("\n");
    }
    
}
