#include "problem_10.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    vector<uint64_t> prime;
    uint64_t sum = 0;

    get_prime_numbers(prime, opt.limit);

    for (auto i : prime) {
        sum += i;
    }

    cout << "Result: " << sum << endl;

    return 0;
}