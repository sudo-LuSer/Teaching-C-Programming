#include <stdio.h>
#include <stdbool.h>
int player_win(char c , char table[3][3]){
    for(int i = 0 ; i < 3 ; i++){
        if(table[i][1]==c){
            if(table[i][0]==table[i][1] && table[i][2]==table[i][1]){
                return 1; 
            }
        }
    }
    for(int i = 0 ; i < 3 ; i++){
        if(table[i][1]){
            if(table[0][i]==table[1][i] && table[2][i]==table[1][i] && table[1][i] == c){
                return 1; 
            }
        }
    }
    if(table[0][0]==table[1][1] && table[1][1]==table[2][2] && table[0][0]==c){
        return 1; 
    }
    return 0; 
}
void print_table(char table[3][3]){
    printf("  1 2 3\n");
    for(int i =0 ; i < 3 ;i++){
        printf("%d " , i+1);
        for(int j = 0 ;j < 3 ;j++){
            printf("%c ",table[i][j]);
        }
        printf("\n");
    }
}
int main(){
    char c[3][3]; 
    for(int i = 0 ; i < 3 ;i++){
        for(int j = 0 ; j < 3 ;j++){
            c[i][j]= '.';
        }
    }
    char player = 'x';
    while(!player_win('x' , c) && (!player_win('o' , c))){
        print_table(c);
        int x , y ;
        printf("%c turn : donner la position ou vous voulais jouez : " , player);
        scanf("%d %d", &x , &y);
        x--; y--; 
        if(c[x][y]=='.'){
            c[x][y] = player; 
            if(player =='x'){
                player = 'o';
            }
            else{
                player = 'x';
            }
        }
        else{
            printf("interdit \n");
        }
    }   
    if(player =='x'){
        player = 'o';
    }
    else{
        player = 'x';
    }
    printf("%c is win " , player);
    return 0; 
}