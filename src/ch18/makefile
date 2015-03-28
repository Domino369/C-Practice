#
#  AUTHOR:    David Storme
#

# Variables
CC      = g++
CCFLAGS = -pthread -std=c++11 -Wall

# Rule to link object code files to create executable file
all: ch18.o ch18-1-1.o
	$(CC) $(CCFLAGS) -o ../../build/ch18 $(LLFLAGS) ch18.o ch18-1-1.o

# Rules to compile source code files to object code
ch18.o: ch18.cpp ch18-1-1.h
	$(CC) $(CCFLAGS) -c ch18.cpp

ch18-1-1.o: ch18-1-1.cpp ch18-1-1.h
	$(CC) $(CCFLAGS) -c ch18-1-1.cpp
    
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o
