#include "rng.h"

#include <stdint.h>
#include <time.h>
#include <stdio.h>


// Setting seed
#define INITIAL_SEED 1
static uint64_t seed = INITIAL_SEED;
void rng_seed_set(uint64_t nseed) { seed = nseed;         }
void rng_seed_time_set()          { seed = time(NULL);    }


// Generate numbers
uint32_t rng_gen()                { return rng_lcg_gen(); }


// LCG generation
static uint64_t lcg_a = 1103515245;
static uint64_t lcg_c = 12345;
static uint64_t lcg_m = (uint64_t)2 << 31;

void rng_lcg_set(uint64_t a, uint64_t c, uint64_t m){
    lcg_a = a;
    lcg_c = c;
    lcg_m = m;
}
uint32_t rng_lcg_gen(){
    seed = (lcg_a * seed + lcg_c) % lcg_m;
    return seed;
}




// LFSR generation
uint64_t lfsr_poly = 0x80000000000019E2;

void rng_lfsr32_set(uint64_t poly){
    lfsr_poly = poly;
}
static uint8_t lfsr_gen(){
    uint8_t bit = seed & 1;

    for (int i = 0; i < 64; i++){
        bit ^= (seed >> i) & ((lfsr_poly >> i) & 1);
    }
    bit &= 1;
    seed = seed >> 1 | (((uint64_t)bit << 63));
    return bit;
}
uint32_t rng_lfsr32_gen(){
    uint32_t num = 0;
    for (int i = 0; i < 32; i++){
        num = num << 1 | lfsr_gen();
    }
    return num;
}


