#include "problem_09.h"
#include "utils.h"

#define MAX 1000

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    for (int a = 1; a < MAX; a++) {
        for (int b = a + 1; b < MAX; b++) {
            double c = sqrt(a * a + b * b);
            if (c - floor(c) == 0 && a + b + c == opt.pythagorean_sum) {
                cout << "a: " << a << " b: " << b << " c: " << c <<endl;
                cout << "a * b * c = " << (int)a*b*c << endl;
                return 0;
            }
        }
    }

    return 0;
}