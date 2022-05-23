/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include <vector>
#include "problem_03.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    vector<uint64_t> prime_factors;

    for (uint64_t i = 2; i < sqrt(opt.number); i++) {
        if (opt.number % i == 0) {
            if (is_prime_number(i)){
                cout << i <<endl;
            }
        }
    }

    return 0;
}
