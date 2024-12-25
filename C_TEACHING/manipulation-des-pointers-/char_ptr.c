#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* my_stpcpy(char* dst, const char* src){
    int i = 0; 
    while(dst[i]!=0 && src[i]!=0){
        dst[i] = src[i];
        i++; 
    }
    return 0;
}
char *my_strcat(char *dst ,const char *src){
    int l = strlen(dst);
    int i = l;
    while(src[i-l]!=0){
        dst[i] = src[i-l];
        i++;
    }
    return dst; 
}
char *myStrCat(char *dst , const char *src){
    int l_d = strlen(dst) , l_s = strlen(src);
    int i = l_d; 
    char P[i];
    my_stpcpy(P , dst);
    realloc(dst , (l_d+l_s)*sizeof(char));
    my_stpcpy(dst , P);
    while(src[i-l_d]!=0){
        dst[i] = src[i-l_d];
        i++; 
    }
    return dst;
}
int my_strcmp(const char *s1 , const char *s2){
    int i = 0 ; 
    while(s1[i]!=0 && s2[i]!=0){
        if(s1[i] < s2[i]){
            return -1; 
        }
        if(s2[i] < s1[i]){
            return 1; 
        }
        i++; 
    }
    if(s1[i]==0 && s2[i]==0){
        return 0; 
    }
    else if(s1[i]==0){
        return -1; 
    }
    return 1; 
}
int main(){
    char *a = malloc(sizeof(char)*4);
    a[0] = 'a'; 
    a[1] = 'b';
    a[2] = 'e';
    a[3] = 'l';
    char *b = "galois"; 
    myStrCat(a,b);
    printf("%s " , a);
    free(a); 
}