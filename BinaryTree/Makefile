#---------
#	MACROS
#---------

CC = g++
FLAGS = -std=c++11 -I $(INCLUDEDIR) -g
SOURCEDIR = src/
BINDIR = bin/
LIBDIR = lib/
INCLUDEDIR = include/
TARGET = $(BINDIR)drive
DRIVE = drive

#---------
#	 RULES
#---------

all: $(TARGET)

$(TARGET): $(LIBDIR)$(DRIVE).o
		$(CC) $^ -o $@ $(FLAGS)  

$(LIBDIR)$(DRIVE).o: $(SOURCEDIR)$(DRIVE).cpp
		mkdir -p $(LIBDIR)
		$(CC) -c $(FLAGS) -o $@ $^  

#---------
#	.PHONY
#---------
.PHONY: clean

clean:
		rm -rf $(LIBDIR) $(TARGET)