#include "problem_21.h"
#include "utils.h"
#include <algorithm>

int main(int argc, char* argv[])
{
   if (parse_opts(argc, argv) != 0)
        exit(1);

    vector<int> sum;
    vector<int> amicals;
    int sum_am = 0;

    for (int i = 0; i < opt.max; i++) {
        vector<int> dividors = get_dividors(i);
        
        sum.push_back(0);

        for (int j = 0; j < dividors.size(); j++) {
            sum[i] += dividors[j];
        }
    }


    for (int i = 0; i < sum.size(); i++) {
        if (sum[i] < sum.size()) {
            if (i == sum[sum[i]] && i != sum[i]) {
                //amicals.push_back(i);
                cout << i << ":" << sum[i] << endl;
                sum_am += sum[i];
            }
        }
    }
    
    cout << "Sum amicals: " << sum_am << endl;

    return 0;
}
