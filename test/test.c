#include "rng.h"
#include <stdio.h>

void print_test(int (*test)()){
    printf(" : %s\n",(*test)() ? "PASSED" : "FAILED");
}

// Test different situations for lcg
int test_lcg_c(){

    printf("TEST LCG SEED C");
    
    rng_seed_set(0);
    rng_lcg_set(11, 3, ((uint64_t) 1) << 31);
    int r = rng_lcg_gen();
    if (r != 3) return 0;

    return 1;
}
int test_lcg_a(){

    printf("TEST LCG SEED A");

    rng_seed_set(1);
    rng_lcg_set(11, 3, ((uint64_t) 1) << 31);
    int r = rng_lcg_gen();
    if (r != 14) return 0;

    return 1;
}
int test_lcg_m(){


    printf("TEST LCG SEED M");

    rng_seed_set(1);
    rng_lcg_set(11, 3, 7);
    int r = rng_lcg_gen();
    if (r != 0) return 0;

    return 1;
}

void test_lcg(){
    print_test(test_lcg_c);
    print_test(test_lcg_a);
    print_test(test_lcg_m);
}

// Test different cases for lfsr
int test_lfsr_poly0(){
    printf("TEST LFSR POLY 0 : ");

    int n = 0xfdec;

    rng_seed_set(n);
    rng_lfsr32_set(0);
    int r = rng_lfsr32_gen();
    if (r != n) return 0;

    return 1;
}
int test_lfsr_poly1(){
    printf("TEST LFSR POLY 1 : ");

    int n = 0xffffcdeb;

    rng_seed_set(n);
    rng_lfsr32_set(1);
    int r = rng_lfsr32_gen();
    if (r != 0) return 0;

    return 1;
}
int test_lfsr_poly2(){
    printf("TEST LFSR POLY 2 : ");

    int n = 0x9;

    rng_seed_set(n);
    rng_lfsr32_set(2);
    int r = rng_lfsr32_gen();
    if (r != 0xd) return 0;

    return 1;
}

void test_lfsr(){
    print_test(test_lfsr_poly0);
    print_test(test_lfsr_poly1);
    print_test(test_lfsr_poly2);
}

int main(){

    // Main tests
    test_lcg();
    test_lfsr();


    return 0;
}