%{
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
0|[1-9][0-9]* { return(CSTE_ENTIERE); }
%%
