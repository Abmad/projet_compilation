%{
#include "arbre.h"
#include "tablexico.h"
#include "y.tab.h"
int numligne=1;
%}
%%
\+ {return(PLUS);}
-  {return(MOINS);}
\* {return(MULT);}
\/ {return(DIV);}
\( {return(PO);}
\) {return(PF);}
\n {numligne++;}
0|[1-9][0-9]* { yylval.typ2=atoi(yytext);return(CSTE_ENTIERE); }
%%
