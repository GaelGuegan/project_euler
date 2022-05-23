/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#include "problem_11.h"
#include "utils.h"
#include <sstream>

void get_2d_vector_from_file(const char* filename, vector<vector<int>> &input)
{
    ifstream file(filename);
    string line;

    while(getline(file, line, '\n')) {

        vector<int> v;
        stringstream line_stream;
        line_stream.str(line);
        string num;

        while (getline(line_stream, num, ' ')) {
            v.push_back(stoi(num));
        }
        input.push_back(v);
    }
}

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    vector<vector<int>> input;
    double mult = 1;

    get_2d_vector_from_file(opt.file, input);

    // HORIZONTAL
    mult = 1;
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0 ; j < input[i].size() - opt.num; j++) {
            double tmp = 1;
            for (int k = 0; k < opt.num; k++) {
                tmp *= input[i][j + k];
            }
            if (tmp > mult)
                mult = tmp;
        }
    }
    cout << "horizontal: " << fixed << mult << endl;

    // VERTICAL
    mult = 1;
    for (int i = 0; i < input.size() - opt.num; i++) {
        for (int j = 0 ; j < input[i].size(); j++) {
            double tmp = 1;
            for (int k = 0; k < opt.num; k++) {
                tmp *= input[i + k][j];
            }
            if (tmp > mult)
                mult = tmp;
        }
    }
    cout << "vertical  : " << fixed << mult << endl;

    // DIAGONAL 1
    mult = 1;
    for (int i = 0; i < input.size() - opt.num - 1; i++) {
        for (int j = 0 ; j < input[i].size(); j++) {
            double tmp = 1;
            for (int k = 0; k < opt.num; k++) {
                tmp *= input[i + k][j + k];
        }
            if (tmp > mult)
                mult = tmp;
        }
    }
    cout << "diago 1   : "<< fixed  << mult << endl;

    // DIAGONAL 2
    mult = 1;
    for (int i = 0; i < input.size() - opt.num; i++) {
        for (int j = input.size() - 1; j >= opt.num - 1; j--) {
            double tmp = 1;
            for (int k = 0; k < opt.num; k++) {
                tmp *= input[i + k][j - k];
            }
            if (tmp > mult)
                mult = tmp;
        }
    }
    cout << "diago 2   : " << fixed << mult << endl;

    return 0;
}
