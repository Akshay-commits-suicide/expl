CC = gcc
LEX = flex
YACC = yacc

TARGET = expr

all: $(TARGET)

$(TARGET): y.tab.c lex.yy.c exptree.c codegen.c
	$(CC) -o $(TARGET) y.tab.c lex.yy.c exptree.c codegen.c

y.tab.c y.tab.h: exptree.y
	$(YACC) -d exptree.y

lex.yy.c: exptree.l y.tab.h
	$(LEX) exptree.l

clean:
	rm -f $(TARGET) lex.yy.c y.tab.h y.tab.c ex1.xsm expr
