# Makefile for executable student

# *****************************************************
# Parameters to control Makefile operation

CC = gcc
CFLAGS = -ansi -g 
ODIR=obj

# ****************************************************
# Entries to bring the executable up to date

student:	main.o functions.o
	$(CC) $(CFLAGS) -o student main.o functions.o

main.o:	main.c functions.h
	$(CC) $(CFLAGS) -c main.c

functions.o:	functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

clean:	
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~