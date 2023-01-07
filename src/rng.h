#ifndef __QLIB_RNG__
#define __QLIB_RNG__


#include <stdint.h>

// Setting seed
void rng_seed_set(uint64_t nseed);
void rng_seed_time_set();


// Generate numbers
uint32_t rng_gen();

// LCG generator
void rng_lcg_set(uint64_t a, uint64_t c, uint64_t m);
uint32_t rng_lcg_gen();

// LFSR generator
void rng_lfsr32_set(uint64_t poly);
uint32_t rng_lfsr32_gen();



#endif