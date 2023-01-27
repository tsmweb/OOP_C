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
#person.o: person.c
#	$(CC) -c $(CCFLAGS) person.c -o person.o
#
#student.o: student.c
#	$(CC) -c $(CCFLAGS) student.c -o student.o
#
#teacher.o: teacher.c
#	$(CC) -c $(CCFLAGS) teacher.c -o teacher.o
%.o: %.c
	$(CC) -c $(CCFLAGS) $^

clean:
	rm -rf *.o

rmproper: clean
	rm -rf $(TARGET)

run: $(TARGET)
	./$(TARGET)