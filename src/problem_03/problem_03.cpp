#include "problem_03.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    vector<uint64_t> prime_factors;

    for (uint64_t i = 2; i < sqrt(opt.number); i++) {
        if (opt.number % i == 0) {
            if(is_prime_number(i)){
                cout << i <<endl;
            }
        }
    }

    return 0;
}