#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
typedef struct point point;
struct point{
    int x;
    int y; 
};
float norme(point p1, point p2){
    float pt_1 = p1.x - p2.x , pt_2 = p1.y - p2.y;
    double pt = pt_1*pt_1 + pt_2*pt_2;
    float res = sqrt(pt);
    return res;
}
double *E(point *PT , int n){
    double *Esp = (double*) malloc(sizeof(double)*2);
    Esp[0] = 0.0; 
    Esp[1] = 0.0;
    for(int i = 0 ; i < n ; i++){
        Esp[0] += ((float)(PT[i].x) / ((float)(n)));
        Esp[1] += ((float)(PT[i].y)/((float) (n))); 
    } 
    return Esp; 
}
double *V(point *PT , int n){
    double *V = (double*) malloc(sizeof(double)*2);
    V[0] = 0.0; 
    V[1] = 0.0;
    for(int i = 0 ; i < n ; i++){
        V[0] += ((float)(PT->x) - E(PT , n)[0])/((float)(n));
        V[0] *= ((float)(PT->x) - E(PT , n)[0])/((float)(n));
        V[1] += ((float)((PT +1)->y) - E(PT , n)[1])/((float)(n)); 
        V[1] *= ((float)((PT +1)->y) - E(PT , n)[1])/((float) (n));
    } 
    return V;
}
double COV(point *PT , int n){
    double value = 0.0; 
    for(int i = 0 ; i < n ; i++){
        value += (PT->x - E(PT , n)[0])*((PT +1)->y - E(PT , n)[1]);
    }
    return value;
}
int main(){
    point pt[5];    
    for(int i = 0 ; i < 5 ;i++){
        int x_i , y_i;
        scanf("%d %d" , &x_i , &y_i);
        pt[i].x = x_i; 
        pt[i].y = y_i;
    }
    printf("%lf %lf\n" , V(pt , 5)[0] , E(pt , 5)[0]);
    double a = COV(pt , 5) / V(pt , 5)[0];
    double b = (E(pt , 5)[1] - a*E(pt , 5)[0]);
    int t = 10;
    while(t--){
        int x = rand() % 20;
        printf("la valeur corespondant pour x = %d est %lf \n" , x , a*x +b);
    }
    return 0; 
}