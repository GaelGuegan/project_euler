/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_01.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    int sum = 0;
    for (int i = 0; i < opt.limit; i++) {
        if ( (i % opt.div_1 == 0) || (i % opt.div_2 ==0))
            sum += i;
    }

    cout << "Result: " << sum << endl;

    return 0;
}




