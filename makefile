CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
OUT = ceditor

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(SRC) -o $(OUT) $(CFLAGS)

clean:
	rm -f $(OUT)
