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