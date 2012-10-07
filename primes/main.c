//
//  main.c
//  primes
//
//  Created by kode on 10/7/12.
//  Copyright (c) 2012 Bosky. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 1000
long bitmap[MAX];
int _index=0;

static void
_bin (long number)
{
    char * digits;
    int n_digits;
    int i;
    long copy;
    
    /* Count how many digits are necessary. */
    
    copy = number;
    n_digits = 0;
    while (copy) {
        n_digits++;
        copy /= 2;
    }
    
    /* Get space for the digits. */
    
    digits = malloc (n_digits);
    if (! digits) {
        fprintf (stderr, "No more memory.\n");
        exit (EXIT_FAILURE);
    }
    
    /* Fill the digits from the number. */
    
    i = 0;
    copy = number;
    while (copy) {
        digits[i] = copy % 2;
        copy /= 2;
        i++;
    }
    
    /* Output stage. */

    for (i = n_digits - 1; i >= 0; i--) {
        printf ("%d", digits[i]);
    }
    free (digits);
}

int
isPrime_bit(long m){
    int res=1;
    for(int i=0;i<_index;i++){
        printf("\n\t %lu (",m);_bin(m);printf(") & %lu (",bitmap[i]);_bin(bitmap[i]);printf(") ? => %lu", m & bitmap[i]);
        long _bitwise = (m & bitmap[i]);
        if (_bitwise ){
            //printf("\n\t %lu (%s) & %lu (%s) ? %d",m,s1,bitmap[i],s2,res);
            res=0;
        }
        
    }
    if(res){
        printf("\n %lu is prime since its not divisible by upto %d elements of bitmap\n",m,_index);
        bitmap[_index++]=m;
    }
    return (m<10)?1:0;
}

void printBinary(long m,int n){
    int _prime=1;
    for(long i=3;i<n;i+=2){
        printf("\n %lu [",m);_bin(m);printf("] & %lu [",i);_bin(i);printf("] => %lu",m&i);
        if((m&i) == m){
            printf("\n %lu [",m);_bin(m);printf("] & %lu [",i);_bin(i);printf("] => %lu",m&i);
            printf(" *");
            _prime=0;
        }
    }
    if(_prime){
        printf("\n %lu is prime",m);
    }
}

int
isPrime(long m){
    int res=1;
    for(int i=0;i<_index && res;i++){
        //printf("\nis %lu div by %lu = %lu ? ",m,bitmap[_index-1], m % bitmap[_index-1]);
        if(m % bitmap[i] == 0){
            res=0;
        }
    }
    if(res){
        bitmap[_index++]=m;
    }
    return res;
}

void
calculatePrimes(){
    int ctr=0;
    for(long i=3; ctr<MAX;i+=2){
        if(isPrime(i)){
            ++ctr;
            printf("\n prime%d %lu ",ctr,i);
        }
    }
}

int main(int argc, const char * argv[])
{
    //for(long i=2;i<20;i++){
    //    printBinary(i,20);
    //}
    calculatePrimes();
    return 0;
}

