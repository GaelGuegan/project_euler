#include "problem_13.h"
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

    while(getline(file, line)) {
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
