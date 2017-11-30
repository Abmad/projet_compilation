CC=gcc

compilateur : y.tab.c lex.yy.o ./Arbre/arbre.o ./Table_lexico/tablexico.o ./Table_regions/table_regions.o ./Table_representation/representation_entetes_sous_programmes.o ./Table_declarations/table_declaration.o ./Associations_noms/association_noms.o
	$(CC) y.tab.c lex.yy.o ./Arbre/arbre.o ./Table_lexico/tablexico.o ./Table_regions/table_regions.o ./Table_representation/representation_entetes_sous_programmes.o ./Table_declarations/table_declaration.o ./Associations_noms/association_noms.o -ll -o compilateur

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

table_regions.o : ./Table_regions/table_regions.c ./Table_regions/table_regions.h
	$(CC) -c ./Table_regions/table_regions.c

table_representation.o : ./Table_representation/representation_entetes_sous_programmes.c ./Table_representation/representation_entetes_sous_programmes.h
	$(CC) -c ./Table_representation/representation_entetes_sous_programmes.c

table_declaration.o : ./Table_declarations/table_declaration.c ./Table_declarations/table_declaration.h
	$(CC) -c ./Table_declarations/table_declaration.c

associations_nom.o : ./Associations_noms/association_noms.c ./Associations_noms/association_noms.h
	$(CC) -c ./Associations_noms/association_noms.c

clean:
	rm -rf Arbre/*.o Table_lexico/*.o Table_regions/*.o Table_representation/*.o Table_declarations/*.o y.* lex.yy.* arbre.txt
