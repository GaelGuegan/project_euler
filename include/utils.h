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
uint64_t get_prime_number(uint32_t nth);
bool     is_prime_number(uint64_t n);
bool     is_palindromic_number(int n);
void     get_pythagorean_triples(vector<int[3]> &v, uint64_t max);
void     get_triangle_numbers(vector<uint64_t> &triangle_numbers, uint64_t max);
uint64_t get_triangle_numbers(uint32_t nth);
void     get_collatz_sequence(vector<uint64_t> &collatz, uint64_t start);
int      get_collatz_sequence_size(uint64_t start);
uint64_t factorial(int i);
int         get_digit(uint64_t number, int n);
vector<int> get_digits(uint64_t number);
vector<int> get_dividors(uint64_t n);
void     print_1d(vector<int> v);
void     print_2d(vector<vector<int>> v);
void     get_binary(int n, int *binary, int size);

#endif

