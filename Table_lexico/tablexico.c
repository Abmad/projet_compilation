#include "tablexico.h"


int longueur_int(int valeur){ //Calcule la longueur d'un entier
    int retour = 0;

    if(valeur < 0)
    {
        retour++;
        valeur = -1 * valeur;
    }

    while(valeur !=0)
    {
        retour++;
        valeur = valeur / 10;
    }
    return retour;
}


//ajoute un lexème dans la table lexicographique
int add_lexeme_char(char* lex){//Créé par Dan Robert Tsoumbou Moutimba
    assert(cpt<LONGUEUR);
	int lexemeExist = lexemeExists(lex);
        if( lexemeExist != -1)return lexemeExist;
            lexeme l;
	    l.exp_lexeme_char = malloc(sizeof(char));
            strcpy(l.exp_lexeme_char,lex);
            l.exp_lexeme_int = 0;
            l.exp_lexeme_double = 0;
            l.longueur = strlen(lex);
            l.suiv = &table_lexico[cpt+1];
            l.hash_code=cpt;
            table_lexico[cpt] = l;
	    cpt++;
            return l.hash_code;
}

int add_lexeme_int(int lex){//Créé par Dan Robert Tsoumbou Moutimba
    assert(cpt2<LONGUEUR);
        if(table_lexico[cpt2].longueur==0 && table_lexico[cpt2].exp_lexeme_int!=lex){
            lexeme l;
            l.exp_lexeme_int = lex;
            l.exp_lexeme_char = NULL;
            l.exp_lexeme_double = 0;
            l.longueur = longueur_int(lex);
            l.suiv = &table_lexico[cpt2+1];
            l.hash_code = cpt2 +1;
            table_lexico[cpt2] = l;

            return l.hash_code;
        }
        else if(table_lexico[cpt2].longueur==longueur_int(lex) && table_lexico[cpt2].exp_lexeme_int==lex){
            return table_lexico[cpt2].hash_code;
        }
        else{
            cpt2 = cpt2 +1;
            add_lexeme_int(lex);
        }
        cpt2=0;
}

int add_lexeme_double(double lex){//Créé par Dan Robert Tsoumbou Moutimba
    assert(cpt3<LONGUEUR);
        if(table_lexico[cpt3].longueur==0 && table_lexico[cpt3].exp_lexeme_int!=lex){
            lexeme l;
            l.exp_lexeme_double = lex;
            l.exp_lexeme_char = 0;
            l.exp_lexeme_int=0;
            l.longueur = longueur_int((int) lex);
            l.suiv = &table_lexico[cpt3+1];
            l.hash_code = cpt3 +1;
            table_lexico[cpt3] = l;

            return l.hash_code;
        }
        else if(table_lexico[cpt3].longueur==longueur_int(lex) && table_lexico[cpt3].exp_lexeme_double==lex){
            return table_lexico[cpt3].hash_code;
        }
        else{
            cpt3 = cpt3 +1;
            add_lexeme_double(lex);
        }
        cpt3=0;
}

void init_tab_lexico(){
    cpt = 0;
    add_lexeme_char("int");
    add_lexeme_char("float");
    add_lexeme_char("bool");
    add_lexeme_char("char");
    add_lexeme_char("string");
    int i;
    for(i=5;i<LONGUEUR;i++){
        table_lexico[i].exp_lexeme_char = malloc(sizeof(char));
        if(table_lexico[i].exp_lexeme_char==NULL){
            exit(-1);
        }
        table_lexico[i].suiv = malloc(sizeof(lexeme));
        if(table_lexico[i].suiv==NULL){
            exit(-1);
        }
        table_lexico[i].exp_lexeme_double = 0.0;
        table_lexico[i].exp_lexeme_int = 0;
        table_lexico[i].longueur = 0;
        table_lexico[i].hash_code = -1;
    }
}

//affiche le contenu de la table jusqu'à la j-ieme case
void affiche_table_lexico(){//Créé par Dan Robert Tsoumbou Moutimba

    int i=0;
    for(i=0;i<LONGUEUR;i++){
            if(table_lexico[i].hash_code==-1) {return;}
            else {
                printf("HashCode: %d,Lexeme: %s,Longueur: %d\n",table_lexico[i].hash_code,
                    table_lexico[i].exp_lexeme_char,table_lexico[i].longueur);
            }
    }
}

char * get_lexeme(int numlex){//Abdelmoghit MADIH
char * val_return = malloc(sizeof(char));
if(table_lexico[numlex].hash_code == -1 || numlex < 0)return "NULL";
strcpy(val_return,table_lexico[numlex].exp_lexeme_char);
return  val_return;
}
int lexemeExists(char * lexeme){
int i,check = -1;
for(i=0;i<LONGUEUR;i++){

if(table_lexico[i].exp_lexeme_char != NULL && table_lexico[i].hash_code != -1){
if(strcmp(table_lexico[i].exp_lexeme_char,lexeme) == 0){
check=i;
break;
}
}
}
return check;
}
