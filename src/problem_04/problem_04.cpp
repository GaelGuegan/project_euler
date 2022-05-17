#include "problem_04.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    int i = 1, j = 1, mult = 0;

    for (; i < pow(10, opt.digit); i++) {
        for (j = 1; j < pow(10, opt.digit); j++) {
            if (is_palindromic_number(i * j) && i * j > mult)
                mult = i * j;
        }
    }

    cout <<  mult << endl;

    return 0;
}
