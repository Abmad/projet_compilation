CC=gcc

compilateur : y.tab.c lex.yy.o ./Arbre/arbre.o ./Table_lexico/tablexico.o
	$(CC) y.tab.c lex.yy.o ./Arbre/arbre.o ./Table_lexico/tablexico.o  -ll -o compilateur

y.tab.c y.tab.h : ./Yacc_Lex/gram.y
	yacc -v -d Yacc_Lex/gram.y

lex.yy.o : lex.yy.c
	$(CC) -c lex.yy.c

lex.yy.c : ./Yacc_Lex/lex.l y.tab.h
	lex Yacc_Lex/lex.l

arbre.o : ./Arbre/arbre.c ./Arbre/arbre.h
	$(CC) -c ./Arbre/arbre.c

tablexico.o : ./Table_lexico/tablexico.c ./Table_lexico/tablexico.h
	$(CC) -c ./Table_lexico/tablexico.c
clean:
	rm -rf Arbre/*.o Table_lexico/*.o y.* lex.yy.*