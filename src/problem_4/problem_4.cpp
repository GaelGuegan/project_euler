#include "problem_4.h"
#include <vector>

bool is_palindromic_number(int n)
{
	int i = 1;
	vector<int> n_array;

    // Convert Integer to Array
	 do {
        i = i * 10;
        n_array.push_back((n%i)/(i/10));
    } while ( n / i != 0);

    // Compare each number
    for (int j = 0; j < n_array.size(); j++) {
        if ( n_array[j] == n_array[n_array.size()-j-1])
            continue;
        else
            return 0;
    }

    return 1;
}

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
