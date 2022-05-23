/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_21.h"
#include "utils.h"
#include <algorithm>

int main(int argc, char* argv[])
{
   if (parse_opts(argc, argv) != 0)
        exit(1);

    vector<int> sum;
    vector<int> amicals;
    int sum_am = 0;

    for (int i = 0; i < opt.max; i++) {
        vector<int> dividors = get_dividors(i);
        
        sum.push_back(0);

        for (int j = 0; j < dividors.size(); j++) {
            sum[i] += dividors[j];
        }
    }


    for (int i = 0; i < sum.size(); i++) {
        if (sum[i] < sum.size()) {
            if (i == sum[sum[i]] && i != sum[i]) {
                //amicals.push_back(i);
                cout << i << ":" << sum[i] << endl;
                sum_am += sum[i];
            }
        }
    }
    
    cout << "Sum amicals: " << sum_am << endl;

    return 0;
}
