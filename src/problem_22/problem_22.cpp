#include "problem_22.h"
#include "utils.h"
#include <algorithm>

vector<int> rotate_array(vector<int> &A, int K)
{
    vector<int> rotate(A.size());
    vector<int> tmp;

    tmp = A;
    
    print_1d(tmp);

    for (int j = 1; j < K+1; j++) {
        for (int i = 0; i < A.size(); i++) {
            if (i == 0)
                rotate[i] = tmp[A.size()-1];
            else
                rotate[i] = tmp[i-1];
        }
        tmp = rotate;
    }

    return rotate;
}

int main(int argc, char* argv[])
{
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> rotate;

    rotate = rotate_array(a, 2);

    print_1d(rotate);
    
    return 0;
}
