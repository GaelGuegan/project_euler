#include "problem_14.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    int size = 0;
    int max = 0;
    uint64_t num = 0;

    for(int i = 1; i < opt.limit ; i++) {
        size = get_collatz_sequence_size(i);
        if (size > max) {
            num = i;
            max = size;
        }
    }
    cout << "Result: " << max << " " << num << endl;

    return 0;
}