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
//  40000 elapsed: 0.168760, by seting upper bound based on MAX/log2(MAX)
//  40000 elapsed: 0.108759, max prime factor:691 pivot:2616.480413l, break if upper bound satisfied
//  40000 elapsed: 0.104322, max prime factor:691 pivot:2666.000000l, compare 0 with variable, instead of vice-versa
//  40000 elapsed: 0.028197, max prime factor:173 pivot:171.149244l, reducing upper bound by a factor 1/log2(MAX). false +ves
//  40000 elapsed: 0.056665, max prime factor:569 pivot:568.545481l, reducing upper bound by a factor 1/log2(MAX) 90% of max factor. still false +ves
//  40000 elapsed: 0.070723, max prime factor:569 pivot:568.545481l, recalculating upper bound in loop
//  40000 elapsed: 0.061341, max prime factor:569 pivot:568.545481l, reusing variables
//
//  Created by Bosky <bosky101@gmail.com> on 10/7/12.
//  Copyright (c) 2012 Bosky. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/**
 * How many primes are you trying to find. useful to target which spot you want 
 * to get on the leaderboard. Made it to #5 with the last commit
 *
 * For benchmarking flip to 40,000
 * For testing, flip to http://primes.utm.edu/lists/small/1000.txt and compare last
 * For making it to #5 on the leaderboard on http://hackerrank.com, flipped to 195100 :)
 */
#define MAX 40000//40000
int bitmap[MAX];
int _index=0;
int _max_factor=0;
double _pivot;

void calculatePrimes(int);

int
main(int argc, const char * argv[]){
    calculatePrimes(MAX);
    return 0;
}

int
isPrime(int m){
    //int m_2=m/2;
    for(int i=0,_next=0;i<_index;i++){
        int n = bitmap[i];
        /*if(n > m_2){
            break;
        }*/
        //printf("\n\tis %d %% %d = %d ?",m,bitmap[i], m % bitmap[i]);
        if(0==(m % n)){
            //printf("\n\tis %d %% %d = %d !",m,bitmap[i], m % bitmap[i]);
            _max_factor = (_max_factor<n)?n:_max_factor;
            m=0;break;
        }
        if(n > _pivot){
            //printf("\n\t %d > %d",m,bitmap[i], m % bitmap[i]);
            _next=1;
            break;
        }
    }
    if(m){
        //printf("\n%d not div: ",m);for(int j=0;j<_index;j++){printf(" %d",bitmap[j]);}printf("\n");
        bitmap[_index++]=m;m=1;
    }
    return m;
}

void
calculatePrimes(_MAX){
    clock_t start = clock() ;

    printf("2 ");
    //_pivot = (_MAX*0.9 /(log10(_MAX) * log2(_MAX))); //571
    //_pivot += (log10(_MAX)*_MAX/1600);
    for(int i=3,ctr=0; ctr<_MAX;i+=2){
        //_pivot = (_MAX/log2(_MAX)); //691
        _pivot = (_MAX /(log10(_MAX) * log2(_MAX))); //571
        if(isPrime(i)){
            printf("%d ",i);++ctr;
        }
    }
    clock_t end = clock() ;
    double elapsed_time = (end-start)/(double)CLOCKS_PER_SEC ;
    printf(" \n%d elapsed: %f, max prime factor:%d pivot:%fl",_MAX, elapsed_time,_max_factor,_pivot);
}