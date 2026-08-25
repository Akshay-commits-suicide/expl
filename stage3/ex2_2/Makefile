CC = gcc

TARGET = inter

.SUFFIXES:

all: $(TARGET)

$(TARGET): y.tab.c lex.yy.c exptree.c exptree.h codegen.c y.tab.h
	$(CC) -o $(TARGET) y.tab.c lex.yy.c exptree.c codegen.c

y.tab.c y.tab.h: exptree.y exptree.h
	yacc -d exptree.y

lex.yy.c: exptree.l y.tab.h exptree.h
	lex exptree.l

clean:
	rm -f $(TARGET) y.tab.c y.tab.h lex.yy.c ex2.xsm out.xsm inter compiler
