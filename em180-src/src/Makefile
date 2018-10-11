# Makefile for Z80 emulator package
# Don Goodeve  Wed May 14 19:49:35 BST 1997
TARDATE=28Sep98

# Marat Fayzullin's code extracted from
# http://www.freeflight.com/fms/EMUL8/Z80-032797.tar.Z
Z80DIR=../Z80

CC=gcc
CFLAGS=-O2 -I$(Z80DIR) -I../include -DLSB_FIRST
YACC=bison -d
YACCFLAGS=
LEX=lex 
LEXFLAGS=

OBJECTS=dasm.o Z80.o\
        disass.o download.o monitor.o numcode.o store.o z80state.o\
	lexer.o command.o emulator.o registers.o
SOURCE=emucmd.lex emucmd.y dasm.c.patch\
       disass.c download.c hexdump.c monitor.c numcode.c store.c z80state.c\
       registers.c emulator.c
INCLUDE=disass.h download.h monitor.h numcode.h store.h terminal.h types.h\
	z80state.h registers.h emulator.h
TEST=distest loadtest montest numtest sttest ltest ptest
INTERM=emucmd.tab.c emucmd.tab.h lex.yy.c newdasm.c
APPS=hexdump dasm80 em80


# Major targets
#######################################################################
all:	$(APPS)
	
clean:
	rm -f $(TEST) $(OBJECTS) $(INTERM)

tarfile:	Makefile $(SOURCE) $(INCLUDE) ../README clean
	cd ..;\
	tar -cvf EM80.$(TARDATE).tar README src/* man/*;\
	gzip -v9 EM80.$(TARDATE).tar;\
	cd src

# Applications
#######################################################################
hexdump:	hexdump.c monitor.o numcode.o $(INCLUDE)
	$(CC) $(CFLAGS) -o hexdump hexdump.c monitor.o numcode.o

dasm80:	$(Z80DIR)/dasm.c
	$(CC) $(CFLAGS) $(Z80DIR)/dasm.c -o dasm80

em80:	$(OBJECTS)
	$(CC) $(CFLAGS) -o em80 $(OBJECTS)

# Patches
newdasm.c: $(Z80DIR)/dasm.c dasm.c.patch
	patch $(Z80DIR)/dasm.c -o newdasm.c < dasm.c.patch

# Object files
dasm.o:	newdasm.c
	$(CC) $(CFLAGS) -DDASMOBJONLY -c newdasm.c -o dasm.o

Z80.o:	$(Z80DIR)/Z80.c
	$(CC) $(CFLAGS) -DDEBUG -c $(Z80DIR)/Z80.c -o Z80.o

emulator.o:	cmdtypes.h emucmd.tab.h help.h store.h
	$(CC) -c $(CFLAGS) emulator.c -o emulator.o

.c.o:	
	$(CC) -c $(CFLAGS) $*.c -o $*.o

# Parser/Lexer objects
#######################################################################
lexer.o:	lex.yy.c emucmd.tab.h
	$(CC) -c $(CFLAGS) lex.yy.c -o lexer.o

command.o:	emucmd.tab.c emucmd.tab.h cmdtypes.h
	$(CC) -c $(CFLAGS) emucmd.tab.c -o command.o

lex.yy.c:	emucmd.lex emucmd.tab.h cmdtypes.h
	$(LEX) $(LEXFLAGS) emucmd.lex

emucmd.tab.c:	emucmd.y cmdtypes.h
	
emucmd.tab.h:	emucmd.y cmdtypes.h
	$(YACC) $(YACCFLAGS) emucmd.y

#######################################################################
# Test codes
distest:	disass.c numcode.o dasm.o $(INCLUDE)
	$(CC) $(CFLAGS) -DTEST -o distest disass.c numcode.o z80emu/dasm.o

loadtest:	download.c monitor.o numcode.o $(INCLUDE)
	$(CC) $(CFLAGS) -DTEST -o loadtest download.c monitor.o numcode.o

montest:	monitor.c numcode.o $(INCLUDE)
	$(CC) $(CFLAGS) -DTEST -o montest monitor.c numcode.o

numtest:	numcode.c $(INCLUDE)
	$(CC) $(CFLAGS) -DTEST -o numtest numcode.c 

sttest:		z80state.c numcode.o $(INCLUDE)
	$(CC) $(CFLAGS) -DTEST -o sttest z80state.c numcode.o

ltest:	lex.yy.c emucmd.tab.h cmdtypes.h numcode.o
	$(CC) $(CFLAGS) -DTEST -o ltest lex.yy.c numcode.o

ptest:	emucmd.tab.c lexer.o numcode.o emulator.h
	$(CC) $(CFLAGS) -DTEST -o ptest emucmd.tab.c lexer.o numcode.o

