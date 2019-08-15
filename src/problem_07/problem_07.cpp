#include "problem_07.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    cout << opt.prime << "-th prime number: ";
    cout << get_prime_number(opt.prime) << endl; 

    return 0;
}