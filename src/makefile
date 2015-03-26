#
#  AUTHOR:    David Storme
#

# Variables
CC      = g++
CCFLAGS = -std=c++11 -Wall

all: main.o

# Rules to compile source code files to object code
main.o: main.cpp
	$(CC) $(CCFLAGS) -c main.cpp
    
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o