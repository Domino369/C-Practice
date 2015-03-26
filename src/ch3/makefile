#
#  AUTHOR:    David Storme
#

# Variables
CC      = g++
CCFLAGS = -std=c++11 -Wall

# Rules to compile source code files to object code
all: ch3.o ch3-1-1.o

ch3.o: ch3.cpp ch3.h ch3-1-1.h
	$(CC) $(CCFLAGS) -c ch3.cpp

ch3-1-1.o: ch3-1-1.cpp ch3-1-1.h
	$(CC) $(CCFLAGS) -c ch3-1-1.cpp
    
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o