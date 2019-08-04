#include "utils.h"

uint64_t get_prime_numbers(vector<uint64_t> &v, uint64_t max)
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
	return v.size();
}

uint64_t get_prime_numbers(uint32_t nth)
{
	vector<uint64_t> v = {2};
	int i = 2;

	do {
		for (auto it = v.begin() ; it < v.end(); ++it) {
			if ( i % *it == 0) {
				break;
			}
			if ( it == v.end() - 1){
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
        if ( n_array[j] == n_array[n_array.size()-j-1])
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