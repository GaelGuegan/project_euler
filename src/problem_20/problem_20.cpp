/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_20.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    uint64_t num = factorial(10);
    vector<int> digits;
    int total = 0;

    cout << "num: " << num << endl;
 
    digits = get_digits(num);
    print_1d(digits);

    for (int i = 0; i < digits.size(); i++) {
        total += digits[i];
    }

    cout << "Total: " << total << endl;

    return 0;
}
