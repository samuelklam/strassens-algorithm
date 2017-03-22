#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int size = 50;

double f(double n){
    return 2*pow(n,3)-pow(n,2);
}

double min(double a, double b){
    if(a < b){
        return a;
    }
    else {
        return b;
    }
}

void s(double n, double f_table[], double s_table[]){
    if(n == 1){
        f_table[0] = 1;
        s_table[0] = 1;
    } else {
        f_table[(int)n - 1] = f(n);
        s_table[(int)n - 1] = 18*pow(ceil(n/2),2) + 7 * min(s_table[(int)ceil(n/2) - 1], f(ceil(n/2)));
    }
}

int main(){
    double f_table[size];
    double s_table[size];
    for(int n = 1; n < size+1; n ++){
        s(n, f_table, s_table);
    }
    for(int i = 0; i < size; i++){
        printf("f_table: n: %d, %f      ", i+1, f_table[i]);
        printf("s_table: n: %d, %f      ",i+1, s_table[i]);
        if(f_table[i] < s_table[i]){
            printf("fastest: n: %d, Conventional\n", i + 1);
        } else {
            printf("fastest: n: %d, Strassen\n", i + 1);
        }
    }
}


