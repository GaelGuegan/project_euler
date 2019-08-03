#include "problem_3.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    vector<uint64_t> prime_numbers;
    get_prime_numbers(prime_numbers, 100);//opt.number);

    return 0;
}




