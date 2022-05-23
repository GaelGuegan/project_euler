/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_09.h"
#include "utils.h"

#define MAX 1000

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    for (int a = 1; a < MAX; a++) {
        for (int b = a + 1; b < MAX; b++) {
            double c = sqrt(a * a + b * b);
            if (c - floor(c) == 0 && a + b + c == opt.pythagorean_sum) {
                cout << "a: " << a << " b: " << b << " c: " << c <<endl;
                cout << "a * b * c = " << (int)a*b*c << endl;
                return 0;
            }
        }
    }

    return 0;
}