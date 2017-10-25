%{
	int nbligne;
	int yyerror(){
		printf("erreur de syntaxe en ligne %d\n"nbligne);
	}
%}



%%


0|[1-9][0-9]* {return (ENTIER);}
0|[1-9][0-9]*\.[0-9][0-9]* {return (REEL);}
[>]|[<]|[>=]|[<=]|[==]|[!=] {return (BOOLEEN);}
[a-zA-Z] {return (CARACTERE);}
[a-zA-Z][a-zA-Z] {return (CHAINE);}



%%

