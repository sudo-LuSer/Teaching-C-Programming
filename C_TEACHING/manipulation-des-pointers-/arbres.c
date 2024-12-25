#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct arbre arbre; 
struct arbre{
    int value ; 
    arbre *arbre_droite; 
    arbre *arbre_gauche; 
};
arbre *Creation(int val){
    arbre *a = (arbre*) malloc(sizeof(arbre));
    a->value = val; 
    a->arbre_droite = NULL;
    a->arbre_gauche = NULL; 
    return a; 
}
void insert_BS(arbre *a , int val){
    if(a==NULL){
        a = Creation(val);
    }
    else if(a->value > val){
        if(a->arbre_droite == NULL){
            a->arbre_droite = Creation(val); 

        }
        else{
            insert_BS(a->arbre_droite , val);
        }
    }
    else{
        if(a->arbre_gauche == NULL){
            a->arbre_gauche = Creation(val);
        }
        else{
            insert_BS(a->arbre_gauche , val);
        }
    }
}
int main(){
    arbre *a; 
    a = Creation(1);
    insert_BS(a , 18);
    printf("%d ",a->arbre_gauche->value); 
}