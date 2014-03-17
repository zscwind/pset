CC = gcc
CFLAGS = -g -Wall

objects = main.o pset.o
main: $(objects)
	$(CC) -o main $(objects)

clean:
	rm -rf $(objects) main
