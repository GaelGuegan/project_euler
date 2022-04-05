#include "problem_21.h"
#include "utils.h"
#include <string.h>

int main(int argc, char* argv[])
{
    int binary[32];
    int n = 1041;
    int size = sizeof(binary) / sizeof(int);
    int start = 0, end = 0;
    int count = 0, max = 0;

    memset(binary, -1, size);
    get_binary(n, binary, size);

    cout << n << endl;
    for (int i = 0; i < size; i++) {
        cout << binary[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        if (binary[i] == 1) {
            start = 1;
        }
        if (binary[i] == 0 && start == 1) {
            count++;
        }
        if (binary[i] == 1 && start == 1 && count != 0) {
            end = 1;
            if (count > max)
                max = count;
            count = 0;
        }
    }

    cout << "Result: ";
    if (end)
        cout << max << endl;
    else
        cout << 0 << endl;

    return 0;
}
