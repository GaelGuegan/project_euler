/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_15.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    uint64_t num = 1;

    // Combinatoire with p = 2n and k = n :
    // 2n ! / n! * n!

    // Example of fraction
    // 1 * 2 * 3 * 4 * 5 * 6 * 7 *8
    // 1 * 2 * 3 * 4 * 1 * 2 * 3 * 4

    // Simplification of fraction
    // 5 * 6 * 7 * 8
    // 1 * 2 * 3 * 4

    for (int i = 1; i <= opt.num; i++) {
        num *= i + opt.num;
        num /= i;
    }

    cout << "Result: " << num<< endl;

    return 0;
}