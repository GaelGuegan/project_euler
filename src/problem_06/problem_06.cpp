/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_06.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    int sum = 0;
    int sum_pow = 0;

    for (int i = 1; i <= opt.max_sum; i++) {
        sum += pow(i, 2);
        sum_pow += i;
    }
    sum_pow = pow(sum_pow, 2);

    cout << "Sum     : " << sum << endl;
    cout << "Sum Pow : " << sum_pow << endl;
    cout << "Diff    : " << sum_pow - sum << endl;

    return 0;
}