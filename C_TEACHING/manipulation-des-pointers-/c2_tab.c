#include <stdio.h>
void min_max(int l ,int t[],int *min , int *max){
    *min = t[0];
    *max = t[0];
    for(int i = 1 ;i < l ;i++){
        if(*min > t[i]){
            *min = t[i];
        }
        if(*max < t[i]){
            *max = t[i];
        }
    }
}
int somme_Tab(int l , int tab1[] , int tab2[]){
    for(int i = 0 ; i < l ;i++){
        tab1[i] += tab2[i];
    }
}
int main(){
    int tab[5] = {1,4,2,3,5};
    somme_Tab(5 , tab ,tab);
    int *p = tab; 
    for(int i  = 0 ; i < 5 ;i++){
        printf("%p %d " , p , tab[i]);
        p++; 
    }
    int min , max ;
    min_max(5 , tab , &min , &max);
    printf("%d %d ", min , max);
}