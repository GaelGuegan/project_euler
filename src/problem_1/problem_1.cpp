#include "problem_1.h"

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

     int sum;
	for(int i = 0; i < opt.limit; i++) {
		if ( (i % opt.div_1 == 0) || (i % opt.div_2 ==0))
			sum += i;
	}

	cout << "Result: " << sum << endl;

	return 0;
}




