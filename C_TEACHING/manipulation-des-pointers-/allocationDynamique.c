#include <stdio.h>
#include <stdlib.h>
int *alloc_vec(int len , int val){
    int *tab = malloc(len*sizeof(int));
    for(int i = 0 ; i < len ; i++){
        *(tab + i) = val;
    }
    return tab; 
}
void free_vec(int *vec){
    free(vec); 
}
int *sum_tab(int l , int *tab1 , int *tab2){
    int *sum = alloc_vec(l , 0 );
    for(int i = 0 ; i < l ;i++){
        *(sum + i) = *(tab1 + i) + *(tab2 + i); 
    }
    return sum;
}
int main(){
    int tab1[5] = {1,45,1,2,3};
    int tab2[5] = {55 , 23 , 22 , 88 , 33};
    int *summ = sum_tab(5 , tab1 , tab2);
    for(int i=0 ; i < 5 ;i++){
        printf("%d " , *(summ +i));
    }
    free_vec(summ);
}