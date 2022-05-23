/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_13.h"
#include <string>
#include "utils.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    ifstream file(opt.file);
    string line;
    vector<string> v;
    vector<int> w;
    int unit = 0;
    int carry = 0;
    int sum_tmp = 0;
    int val = 0;

    if (file.fail()) {
        cout << "Error: " << opt.file << " does not exist ! " << endl;
        exit(-1);
    }

    while (getline(file, line)) {
        v.push_back(line);
    }

    for (int i = v[0].size() - 1; i >= 0; i--) {
        unit = 0;
        sum_tmp = 0;
        for (int j = 0; j < v.size(); j++) {
            sum_tmp += v[j][i] - '0';
        }
        unit = sum_tmp % 10;
        w.push_back((unit + carry) % 10);
        carry = (sum_tmp + carry) / 10;
    }
    w.push_back(carry);

    for (int i = w.size() - 1; i >= 0; i--)
        cout << w[i]  << flush;
    cout << endl;

    return 0;
}
