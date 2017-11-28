CC=gcc

compilateur : y.tab.c lex.yy.o arbre.o tablexico.o
	$(CC) y.tab.c lex.yy.o arbre.o tablexico.o  -ll -o compilateur

y.tab.c y.tab.h : gram.y
	yacc -v -d gram.y

lex.yy.o : lex.yy.c
	$(CC) -c lex.yy.c

lex.yy.c : lex.l y.tab.h
	lex lex.l

arbre.o : arbre.c arbre.h
	$(CC) -c arbre.c

tablexico.o : tablexico.c tablexico.h
	$(CC) -c tablexico.c
