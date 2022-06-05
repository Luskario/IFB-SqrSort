TARGET = SqrtSort
CFLAGS = -Wall
CC = gcc
LDFLAGS = -lm

SRC = $(wildcard ./src/*.c)
OBJ = $(SRC:.c =.o)

main: $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<


.PHONY: clean

clean:
	rm main $(OBJ)