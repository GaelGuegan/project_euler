/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_08.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    uint64_t mult_1 = 1;
    uint64_t mult_2 = 0;

    for (int i = 0; i < strlen(opt.big_number) - opt.suite + 1; i++) {
        mult_1 = 1;
        for (int j = i; j < i + opt.suite; j++) {
            mult_1 = mult_1 * (uint64_t)(opt.big_number[j] - '0');
        }
        if (mult_1 > mult_2)
            mult_2 = mult_1;
    }

    cout << "Result: " << mult_2 << endl;

    return 0;
}
