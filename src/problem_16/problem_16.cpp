#include "problem_16.h"
#include "utils.h"
#include <gmp.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    mpz_t res, base;
    char *tmp = NULL;
    int n = 0;

    mpz_init(res);
    mpz_init(base);

    mpz_set_ui(base, opt.num);

    mpz_pow_ui (res, base, opt.power);

    tmp = mpz_get_str (NULL, 10, res);

    for(int i = 0; i < strlen(tmp); i++)
        n += tmp[i] - '0';


    /* OVERFLOW */
    /*
    uint64_t result;
    int n = 0;

    result = pow(opt.num, opt.power);

    while(result) {
        n += result % 10;
        result /= 10;
    }
    */

    cout << "Result: " << n << endl;

    return 0;
}