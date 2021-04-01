TARGET = oop
CC = gcc
CCFLAGS = -Wall
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

all: $(TARGET)

#oop: $(OBJS)
#	$(CC) -o $(TARGET) $(OBJS)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^

#main.o: main.c
#	$(CC) -c $(CCFLAGS) main.c -o main.o
#
#pessoa.o: pessoa.c
#	$(CC) -c $(CCFLAGS) pessoa.c -o pessoa.o
#
#aluno.o: aluno.c
#	$(CC) -c $(CCFLAGS) aluno.c -o aluno.o
#
#professor.o: professor.c
#	$(CC) -c $(CCFLAGS) professor.c -o professor.o
%.o: %.c
	$(CC) -c $(CCFLAGS) $^

clean:
	rm -rf *.o

rmproper: clean
	rm -rf $(TARGET)

run: $(TARGET)
	./$(TARGET)