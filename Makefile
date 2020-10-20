 

CC = gcc

executable: add.o sub.o main.o
	$(CC) -o  executable add.o sub.o main.o

add.o: add.c header.h
	$(CC) -c -o add.o add.c

sub.o: sub.c header.h
	$(CC) -c -o sub.o sub.c
	
main.o: main.c header.h
	$(CC) -c -o main.o main.c
	
clean:
	rm -rf *.o
