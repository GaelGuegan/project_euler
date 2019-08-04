#include "problem_8.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    uint64_t mult_1 = 1;
    uint64_t mult_2 = 0;

    for (int i = 0; i < strlen(opt.big_number) - opt.suite + 1; i++) {
    	mult_1 = 1;
	    for (int j = i; j < i + opt.suite; j++) {
	    	mult_1 = mult_1 * (uint64_t)(opt.big_number[j] - '0');
	    }
	    if (mult_1 > mult_2)
	    	mult_2 = mult_1;
	}

	cout << "Result: " << mult_2 << endl;

    return 0;
}