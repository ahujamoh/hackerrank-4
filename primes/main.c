//
//  main.c
//  primes - a weekend c exercise
//
//  NOTES
//  40,000 elapsed: 13.410259 by skipping even numbers
//  40000 elapsed: 7.828817 by via checking only first half factors
//  40000 elapsed: 5.712772 by checking only first 1/3 factors
//  40000 elapsed: 3.643709 by checking only first 1/5 factors
//  40000 elapsed: 2.705176 by checking only first 1/7 factors
//  40000 elapsed: 0.960590 by checking using int instead of long
//  40000 elapsed: 0.194436, by studying upper bounds of max prime factor (was 691 for 40,000)
//  TODO: use log/exp/proportions to give a lower number for 40,000 , higher number for 1000
//
//  Created by Bosky <bosky101@gmail.com> on 10/7/12.
//  Copyright (c) 2012 Bosky. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * How many primes are you trying to find. useful to target which spot you want 
 * to get on the leaderboard. Made it to #5 with the last commit
 *
 * For benchmarking flip to 40,000
 * For testing, flip to http://primes.utm.edu/lists/small/1000.txt and compare last
 * For making it to #5 on the leaderboard on http://hackerrank.com, flipped to 195100 :)
 */
#define MAX 40000
int bitmap[MAX];
int _index=0;
int _max_factor=0;
int
isPrime(int m){
    int res=1;
    for(int i=0;i<_index;i++){
        int n = bitmap[i];
        //printf("\n\tis %d %% %d = %d ",m,bitmap[i], m % bitmap[i]);
        if(m % n == 0){
            //printf("\n\tis %d %% %d = %d ? so %d is not prime",m,bitmap[i], m % bitmap[i], m / bitmap[i]);
            _max_factor = (_max_factor<n)?n:_max_factor;
            res=0;break;
        }
        if(n > MAX/10){
            break;
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
    printf("2");
    for(int i=3; ctr<MAX;i+=2){
        if(isPrime(i)){
            ++ctr;
            printf("\n %d ",i);
        }
    }
}

int
main(int argc, const char * argv[]){
    clock_t start = clock() ;
    calculatePrimes();
    clock_t end = clock() ;
    double elapsed_time = (end-start)/(double)CLOCKS_PER_SEC ;
    printf(" \n%d elapsed: %f, max prime factor was %d",MAX, elapsed_time,_max_factor );
    return 0;
}
