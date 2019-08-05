#ifndef UTILS
#define UTILS

#include <cstdlib>
#include <vector>
#include <climits>
#include <cstdint>
#include <iostream>
#include <cmath>
#include <array>

using namespace std;

void     get_prime_numbers(vector<uint64_t> &prime_numbers, uint64_t max);
uint64_t get_prime_numbers(uint32_t nth);
bool     is_prime_number(uint64_t n);
bool     is_palindromic_number(int n);
void     get_pythagorean_triples(vector<int[3]> &v, uint64_t max);

#endif