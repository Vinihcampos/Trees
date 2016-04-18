#---------
#	MACROS
#---------

CC = g++
FLAGS = -std=c++11 -I $(INCLUDEDIR) -g
SOURCEDIR = src/
BINDIR = bin/
LIBDIR = lib/
INCLUDEDIR = include/
TARGETBST = $(BINDIR)$(DRIVE)
TARGETBSTWC = $(BINDIR)$(BINARY)
DRIVE = drive
BINARY = binary_tree_sem_classe

#---------
#	 RULES
#---------

bst: $(TARGETBST)
bstwc: $(TARGETBSTWC)

$(TARGETBST): $(LIBDIR)$(DRIVE).o
		$(CC) $^ -o $@ $(FLAGS)  

$(TARGETBSTWC): $(LIBDIR)$(BINARY).o
		$(CC) $^ -o $@ $(FLAGS)  

$(LIBDIR)%.o: $(SOURCEDIR)%.cpp
		mkdir -p $(LIBDIR)
		$(CC) -c $(FLAGS) -o $@ $^  

#---------
#	.PHONY
#---------
.PHONY: clean

clean:
		rm -rf $(LIBDIR) $(TARGET)