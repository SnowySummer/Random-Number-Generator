#include "rng.h"
#include <stdio.h>

void print_test(int (*test)()){
    printf(" : %s\n",(*test)() ? "PASSED" : "FAILED");
}

// Test different situations for lcg
int test_lcg_seedc(){

    printf("TEST LCG SEED C");
    
    rng_seed_set(0);
    rng_lcg_set(11, 3, ((uint64_t) 1) << 31);
    int r = rng_lcg_gen();
    if (r != 3) return 0;

    return 1;
}
int test_lcg_seeda(){

    printf("TEST LCG SEED A");

    rng_seed_set(1);
    rng_lcg_set(11, 3, ((uint64_t) 1) << 31);
    int r = rng_lcg_gen();
    if (r != 14) return 0;

    return 1;
}
int test_lcg_seedm(){


    printf("TEST LCG SEED M");

    rng_seed_set(1);
    rng_lcg_set(11, 3, 7);
    int r = rng_lcg_gen();
    if (r != 0) return 0;

    return 2;
}

void test_lcg(){
    print_test(test_lcg_seedc);
    print_test(test_lcg_seeda);
    print_test(test_lcg_seedm);
}

// Test different cases for lfsr 



int main(){

    // Main tests
    test_lcg();


    return 0;
}