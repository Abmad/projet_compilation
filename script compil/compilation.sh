#!/bin/bash
if [[ ! -z "$1" ]] && [[ ! -z "$2" ]];then
echo "Generating files ..."
lex $1
yacc -v -d $2
gcc -c lex.yy.c
gcc y.tab.c lex.yy.o -o compilation -ly -ll
echo "Done"
else
echo "Usage : ./compilation <fichier lex> <fichier yac>"
fi
