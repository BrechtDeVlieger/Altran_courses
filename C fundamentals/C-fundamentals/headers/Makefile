# the compiler: gcc for C program, define as g++ for C++
  CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall
# the build target executable:
TARGET = test

RM = rm

all: $(TARGET)

scripts.o: scripts.h

$(TARGET).o: scripts.h

$(TARGET): $(TARGET).o scripts.o 
	$(CC) $(CFLAGS) -o $(TARGET) $^

clean:
	$(RM) $(TARGET)
