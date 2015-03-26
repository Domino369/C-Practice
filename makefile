#
#  AUTHOR:    David Storme
#

# Variables
CC      = g++
CCFLAGS = -std=c++11 -Wall

# Rule to link object code files to create executable file
all:
	cd src; make
	cd src/ch3; make
	$(CC) $(CCFLAGS) -o build/practice src/main.o src/ch3/ch3.o src/ch3/ch3-1-1.o
	
clean:
	cd src; make clean
	cd src/ch3; make clean
	-rm build/practice