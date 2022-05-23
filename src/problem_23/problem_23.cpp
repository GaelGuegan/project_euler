/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_23.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    int max = 28123;
    int sum = 0;
    int i = 0;
    int ko = 0;
    vector<uint64_t> abundants;

    if (parse_opts(argc, argv) != 0)
        exit(1);
    
    get_abundant_numbers(abundants, max);

    while (i < max) {
        ko = 0;
        for(int j = 0; j < abundants.size(); j++) {
            if (abundants[j] > i) {
                break;
            }
            for (int k = 0; k < abundants.size(); k++) {
                if (abundants[k] > i) {
                    break;
                }
                if (abundants[k] + abundants[j] == i) {
                    ko = 1;
                }
            }

            if (ko) {
                break;
            }
        }

        if (ko == 0) {
            sum += i;
        }
        i++;
    };
    
    cout << "Total: " << sum << endl;

    return 0;
}
