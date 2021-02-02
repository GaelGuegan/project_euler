#include "utils.h"

void get_prime_numbers(vector<uint64_t> &v, uint64_t max)
{
	v = {2};

	for (uint64_t i = 2; i < max; i++) {
		for (auto it = v.begin() ; it < v.end(); ++it) {
			if ( i % *it == 0) {
				break;
			}
			if ( it == v.end() - 1){
				v.push_back(i);
				break;
			}
		}
	}
}

uint64_t get_prime_number(uint32_t nth)
{
	vector<uint64_t> v = {2};
	int i = 2;

	do {
		for (auto it = v.begin(); it < v.end(); ++it) {
			if (i % *it == 0) {
				break;
			}
			if (it == v.end() - 1){
				v.push_back(i);
				break;
			}
		}
		i++;
	} while (v.size() < nth);

	return v.back();
}

bool is_palindromic_number(int n)
{
	int i = 1;
	vector<int> n_array;

	// Convert Integer to Array
	do {
		i = i * 10;
		n_array.push_back((n%i)/(i/10));
	} while ( n / i != 0);

	// Compare each number
	for (int j = 0; j < n_array.size(); j++) {
		if (n_array[j] == n_array[n_array.size()-j-1])
			continue;
		else
		return 0;
	}

	return 1;
}

bool is_prime_number(uint64_t n)
{
	if (n == 1)
		return 0;

	for (uint64_t i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return 0;
	}

	return 1;
}

void get_pythagorean_triples(vector<array<int, 3>> &v, int max)
{
	for (int a = 0; a < max; a++) {
		for (int b = a + 1; b < max; b++) {
			double c = sqrt(a * a + b * b);
			if (c - floor(c) == 0)
				v.push_back({a, b, (int)c});
		}
	}
}

void get_triangle_numbers(vector<uint64_t> &v, uint64_t max)
{
	v = {1};
	uint64_t triangle = 0;

	for (uint64_t i = 1; i < max; i++) {
		triangle = 0;
		for (int j = 1; j <= i; j++) {
			triangle += j;
		}
		v.push_back(triangle);
	}
}

uint64_t get_triangle_numbers(uint32_t nth)
{
	uint64_t triangle = 0;

	for (int i = 1; i <= nth; i++) {
		triangle += i;
	}

	return triangle;
}

void get_collatz_sequence(vector<uint64_t> &collatz, uint64_t start)
{
	uint64_t num_0 = start;
	uint64_t num_1 = 0;

	collatz.push_back(num_0);

	while (num_1 != 1) {
		if (num_0 % 2 == 0)
			num_1 = num_0 / 2;
		else
			num_1 = 3 * num_0 + 1;
		collatz.push_back(num_1);
		num_0 = num_1;
	}
}

int get_collatz_sequence_size(uint64_t start)
{
	uint64_t num = start;
	int size = 1;

	while (num > 1) {
		if (num % 2 == 0)
			num = num / 2;
		else
			num = 3 * num + 1;
		size++;
	}

	return size;
}

uint64_t factorielle(int n)
{
	uint64_t f = 1;

	for (int i = 1; i <= n; i++){
		f *= i;
	}

	return f;
}

int get_digit(int number, int n)
{
	string number_string = to_string(number);
	int size = number_string.size();

	return (int)number_string[size - n] - '0';
}

void print_1d(vector<int> v)
{
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void print_2d(vector<vector<int>> v)
{
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
