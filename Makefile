TARGET = goscript
CC = gcc
CFLAGS = -I./inc -Wall -Wextra -O2

# On liste explicitement les fichiers sources dans src/
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)

.PHONY: clean

