CC=gcc

compilateur : y.tab.c lex.yy.o TAD_arbre_binaire.o TAD_pile.o tables_hashcode_lexico.o tables_declarations_regions.o allocation.o mon_erreur.o
	$(CC) y.tab.c lex.yy.o TAD_arbre_binaire.o TAD_pile.o tables_hashcode_lexico.o tables_declarations_regions.o allocation.o mon_erreur.o -ly -ll -o compilateur

y.tab.c y.tab.h : compilateur.y
	yacc -v -d compilateur.y

lex.yy.o : lex.yy.c
	$(CC) -c lex.yy.c

lex.yy.c : compilateur.l y.tab.h
	lex compilateur.l

TAD_arbre_binaire.o : includes/TAD_arbre_binaire.c includes/TAD_arbre_binaire.h
	$(CC) -c includes/TAD_arbre_binaire.c

TAD_pile.o : includes/TAD_pile.c includes/TAD_pile.h
	$(CC) -c includes/TAD_pile.c

tables_hashcode_lexico.o : includes/tables_hashcode_lexico.c includes/tables_hashcode_lexico.h
	$(CC) -c includes/tables_hashcode_lexico.c

tables_declarations_regions.o : includes/tables_declarations_regions.c includes/tables_declarations_regions.h
	$(CC) -c includes/tables_declarations_regions.c

allocation.o : includes/allocation.c includes/allocation.h
	$(CC) -c includes/allocation.c

mon_erreur.o : includes/mon_erreur.c includes/mon_erreur.h
	$(CC) -c includes/mon_erreur.c

clean:
	rm -f *.c *.o *.h *~ y.output compilateur
