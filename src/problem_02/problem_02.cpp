/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_02.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    int n = 0, sum = 0;
    int n1 = 1, n2 = 1;

    do {
        n = n1 + n2;
        n1 = n2;
        n2 = n;

        if (n % 2 == 0)
            sum += n;
    } while (n < opt.limit);

    cout << "Result: " << sum << endl;

    return 0;
}
