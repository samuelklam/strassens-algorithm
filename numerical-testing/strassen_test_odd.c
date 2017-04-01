#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int num_pads_odd(int cross_over, int n, int divisions){
    if(n <= cross_over){
        return 0;
    } 
    if(n%2 != 0){
        n++;
        return pow(4, divisions)*(2*n-1) + num_pads_odd(cross_over, n/2, divisions + 1);
    }
    return num_pads_odd(cross_over, n/2, divisions+1);
}

int help_done(int n, int cross_over){
    while(n > cross_over){
        if(n % 2 != 0){
            return 0;
        }
        n = n/2;
        if(n <= cross_over){
            return 1;
        }
    }
    return 1;
}

int num_pads_opt(int cross_over, int n){
    int pad = 0;
    while(1){
        if(help_done(n+pad, cross_over)){
            break;
        }
        else{
            pad++;
        }
    }
    return pad*(2*n+1);
}

int num_pads_pow2(int cross_over, int n){
    while(cross_over < n){
        cross_over = cross_over*2;
    }
    return pow(cross_over,2) - pow(n, 2);
}

void run_test(int start, int end, int cross_over, FILE *f){
    for(int i = start; i <= end; i++){
        fprintf(f, "%d %d %d %d \n", i,num_pads_odd(cross_over, i, 0), num_pads_opt(cross_over, i), num_pads_pow2(cross_over, i));
    }
}

int main(){
    FILE *f = fopen("pad_timings.txt", "w");

    run_test(64, 2048, 64, f);
    fclose(f);
}


