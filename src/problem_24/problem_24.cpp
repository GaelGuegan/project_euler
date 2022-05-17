#include "problem_24.h"
#include "utils.h"
#include <algorithm>
/*
static int N = 3;
static int MAX = 3;
vector<vector<int>> total_array;

void heap(int n, vector<int> &array)
{
    if (n == 1) {
        cout << n << endl;
    } else {
        heap(n - 1, array);
        for (int i = 0; i < n - 1; i++) {
            if (n % 2 == 0) {
                swap(array[i], array[n-1]);
            } else {
                swap(array[0], array[n-1]);
            }
            heap(n - 1, array);
        }
    }
    
}

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    vector<int> array = {0, 1, 2, 3};

    heap(4, array);
    
    return 0;
}*/

// Prints the array
void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    printf("\n");
}
 
// Generating permutation using Heap Algorithm
void heapPermutation(int a[], int size, int n)
{
    // if size becomes 1 then prints the obtained
    // permutation
    if (size == 1) {
        printArr(a, n);
        return;
    }
 
    for (int i = 0; i < size; i++) {
        heapPermutation(a, size - 1, n);
 
        // if size is odd, swap 0th i.e (first) and
        // (size-1)th i.e (last) element
        if (size % 2 == 1)
            swap(a[0], a[size - 1]);
 
        // If size is even, swap ith and
        // (size-1)th i.e (last) element
        else
            swap(a[i], a[size - 1]);
    }
}
 
// Driver code
int main()
{
    int a[] = { 1, 2, 3, 5, 6, 7 };
    int n = sizeof a / sizeof a[0];
    heapPermutation(a, n, n);
    return 0;
}
