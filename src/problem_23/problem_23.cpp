#include "problem_23.h"
#include "utils.h"
#include <algorithm>

int odd_occurrences(vector<int> &A)
{
    sort(A.begin(), A.end());

    for (int i = 0; i < A.size()-1; i=i+2) {
        if (A[i] == A[i+1])
            continue;
        else
            return A[i];
    }

    return -1;
}

int main(int argc, char* argv[])
{
    vector<int> odd = {1, 6, 6, 6, 7, 8, 8, 7, 2, 1, 6};
    int index = -1;

    index = odd_occurrences(odd);

    cout << "Result: " << index << endl;

    return 0;
}
