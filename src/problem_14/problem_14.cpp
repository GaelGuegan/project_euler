/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_14.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    int size = 0;
    int max = 0;
    uint64_t num = 0;

    for (int i = 1; i < opt.limit ; i++) {
        size = get_collatz_sequence_size(i);
        if (size > max) {
            num = i;
            max = size;
        }
    }
    cout << "Result: " << max << " " << num << endl;

    return 0;
}
