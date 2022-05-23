/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_12.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    int i = 0;
    int div = 0;
    int triangle = 0;

    do {
        i++;
        triangle += i;
        div = 0;
        for (int j = 1; j <= triangle; j++) {
            if (triangle % j == 0)
                div++;
        }
    } while (opt.divisors > div);

    cout << "Result: " << triangle << endl;

    return 0;
}
