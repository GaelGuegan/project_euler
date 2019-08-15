#include "problem_12.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    int i = 0;
    int div = 0;
    int triangle = 0;

    do {
        i++;
        triangle += i;
        div = 0;
        for (int j = 1; j <= triangle; j++) {
            if (triangle % j == 0)
                div++;
        }
    } while (opt.divisors > div);

    cout << "Result: " << triangle << endl;

    return 0;
}
