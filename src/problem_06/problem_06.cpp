#include "problem_06.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    int sum = 0;
    int sum_pow = 0;

    for (int i = 1; i <= opt.max_sum; i++) {
        sum += pow(i, 2);
        sum_pow += i;
    }
    sum_pow = pow(sum_pow, 2);

    cout << "Sum     : " << sum << endl;
    cout << "Sum Pow : " << sum_pow << endl;
    cout << "Diff    : " << sum_pow - sum << endl;

    return 0;
}