/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_04.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    int i = 1, j = 1, mult = 0;

    for (; i < pow(10, opt.digit); i++) {
        for (j = 1; j < pow(10, opt.digit); j++) {
            if (is_palindromic_number(i * j) && i * j > mult)
                mult = i * j;
        }
    }

    cout <<  mult << endl;

    return 0;
}
