#include "problem_20.h"
#include "utils.h"

int main(int argc, char* argv[])
{
    uint64_t num = factorial(10);
    vector<int> digits;
    int total;

    cout << "num: " << num << endl;
 
    digits = get_digits(num);
    print_1d(digits);

    for (int i = 0; i < digits.size(); i++) {
        total += digits[i];
    }

    cout << "Total: " << total << endl;

    return 0;
}
