#!/bin/bash
if [[ ! -z "$1" ]] && [[ ! -z "$2" ]];then
echo "Generating files ..."
logf=compilation.log
touch $logf
lex $1 2> $logf 
yacc -v -d $2 2> $logf
gcc -c lex.yy.c 2> $logf
gcc -c ./includes/*.c
gcc y.tab.c lex.yy.o ./includes/*.o -o compilation -ly -ll 2> $logf
echo "Done! check log for more details"
else
echo "Usage : ./compilation <fichier lex> <fichier yac>"
fi
