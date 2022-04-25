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
    n_array = get_digits(n);

	// Compare each number between start and end
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

uint64_t factorial(int n)
{
    /*
	uint64_t f = 1;

	for (int i = 1; i <= n; i++){
		cout << f << " " << i << endl;
        f *= i;
        if ((i+1)  > ULLONG_MAX / f) {
            cerr << "======    !!! OVERFLOW !!!   ==========" << endl;
            cerr << "UINT64_MAX     : " << UINT64_MAX << " " << to_string(UINT64_MAX).size() << endl;
            cerr << "ULLONG_MAX     : " << ULLONG_MAX << endl;
            cerr << "i              : " << i << endl;
            cerr << "ULLONG_MAX / f : " << ULLONG_MAX / f << endl; 
            cerr << "f              : " << f << " " << to_string(f).size() << endl << endl;
       }
	}

	return f;
    */
    
     if (n == 0)
         return 1;
     if (factorial(n-1) > ULLONG_MAX / n) {
        cerr << "===== !!! OVERFLOW !!! ====" << endl;
        cerr << "value n  : " << n << endl;
        cerr << "value n-1: " << n-1 << endl;
        return 1;
     }
     return (n * factorial(n - 1));

}

int get_digit(uint64_t number, int n)
{
	string number_string = to_string(number);
	int size = number_string.size();

	return (int)number_string[size - n] - '0';
}

vector<int> get_digits(uint64_t number)
{
    /*vector<int> digits;
    int size = to_string(number).size();
    
    for (int i = 1; i < size+1; i++) {
        digits.push_back(get_digit(number, i));
    }*/

  	vector<int> digits;
    int i = 1;

	do {
		i = i * 10;
		digits.push_back((number%i)/(i/10));
	} while (number / i != 0);


    return digits;
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

void get_binary(int n, int *binary, int size)
{
    if (binary == NULL) {
        cerr << "Binary conversion impossible: array should be allocated." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        binary[i] = (n & (1 << i)) >> i ;
    }

}

vector<int> get_dividors(uint64_t n)
{
    vector<int> dividors;
    
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            dividors.push_back(i);
        }
    }

    return dividors;

}

void get_perfect_numbers(vector<uint64_t> &perfect_numbers, uint64_t max)
{
    for (int i = 0; i < max; i++) {
        int sum = 0;
        for (int j = 0; j < i; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }
        if (sum == i) {
            perfect_numbers.push_back(i);
        }
    }
}

void get_abundant_numbers(vector<uint64_t> &abundant_numbers, uint64_t max)
{
    for (int i = 1; i < max; i++) {
        int sum = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }
        if (sum > i) {
            abundant_numbers.push_back(i);
        }
    }
}
