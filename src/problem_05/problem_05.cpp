#include "problem_05.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    int number = opt.max_divider;
    int even = 0;

    do {
        for (int i = 1; i < opt.max_divider; i++) {
            if (number % i == 0) {
                even = number;
                continue;
            } else {
                even = 0;
                break;
            }
        }
        number++;
    } while (!even);

    cout << "Result: " << even << endl;

    return 0;
}