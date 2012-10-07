//
//  main.c
//  primes
//
//  Created by Bosky <bosky101@gmail.com> on 10/7/12.
//  Copyright (c) 2012 Bosky. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 40000
long bitmap[MAX];
int _index=0;

int
isPrime(long m){
    int res=1;
    for(int i=0;i<_index;i++){
        long n = bitmap[i];
        if(m % n == 0){
            //printf("\n\tis %lu %% %lu = %lu ? so %lu is not prime",m,bitmap[i], m % bitmap[i], m / bitmap[i]);
            res=0;break;
        }
        /*if(n > m/2){
            break;
        }*/
    }
    if(res){
        bitmap[_index++]=m;
    }
    return res;
}

void
calculatePrimes(){
    int ctr=0;
    printf("2 ");
    for(long i=3; ctr<MAX;i+=2){
        if(isPrime(i)){
            ++ctr;
            printf("\n%lu ",i);
        }
    }
}

int main(int argc, const char * argv[]){
    clock_t start = clock() ;
    calculatePrimes();
    clock_t end = clock() ;
    double elapsed_time = (end-start)/(double)CLOCKS_PER_SEC ;
    printf(" \nelapsed: %f", elapsed_time );
    return 0;
}

