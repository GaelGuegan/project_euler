/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_05.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    int number = opt.max_divider;
    int even = 0;

    do {
        for (int i = 1; i < opt.max_divider; i++) {
            if (number % i == 0) {
                even = number;
                continue;
            } else {
                even = 0;
                break;
            }
        }
        number++;
    } while (!even);

    cout << "Result: " << even << endl;

    return 0;
}
