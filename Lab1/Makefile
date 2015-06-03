#############################################################################
# Makefile for building: admin-console
#############################################################################

####### Compiler, tools and options

CC            = gcc
CFLAGS        = -Wall
LIBS          = -ldl

####### Files

SOURCES = main.c
OBJECTS = main.o

TARGET  = main

####### Build rules

all: $(TARGET)

clean:
	$(RM) -f $(TARGET) *.o *~

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
