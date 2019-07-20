#include "problem_2.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    int n = 0, sum = 0;
    int n1 = 1, n2 = 1;

    do {
        n = n1 + n2;
        n1 = n2;
        n2 = n;

        if (n % 2 == 0)
            sum += n;

    } while (n < opt.limit);

    cout << "Result: " << sum << endl;

    return 0;
}




