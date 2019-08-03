#ifndef UTILS
#define UTILS

#include <cstdlib>
#include <vector>
#include <climits>
#include <cstdint>
#include <iostream>
#include <cmath>

using namespace std;

uint64_t get_prime_numbers(vector<uint64_t> &prime_numbers, uint64_t max);
bool is_prime_number(uint64_t n);

#endif