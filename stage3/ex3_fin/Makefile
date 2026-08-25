CC = gcc

TARGET = inter

FINAL = compiler

.SUFFIXES:

all: $(TARGET)

$(TARGET): y.tab.c lex.yy.c exptree.c exptree.h codegen.c y.tab.h
	$(CC) -o $(TARGET) y.tab.c lex.yy.c exptree.c codegen.c

y.tab.c y.tab.h: exptree.y exptree.h
	yacc -d exptree.y

lex.yy.c: exptree.l y.tab.h exptree.h
	lex exptree.l

label.yy.c: label.l
	lex -o label.yy.c label.l

$(FINAL): label.yy.c
	$(CC) -o $(FINAL) label.yy.c

ex2.xsm: program1.txt $(TARGET)
	./$(TARGET) program1.txt

final.xsm: ex2.xsm $(FINAL)
	./$(FINAL) ex2.xsm final.xsm

clean:
	rm -f $(TARGET) y.tab.c y.tab.h lex.yy.c label.yy.c ex2.xsm final.xsm inter compiler
