# Nombre del ejecutable
EXEC = main

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I.

# Archivos fuente y objetos
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Regla principal
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos compilados
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: clean