#include "problem_22.h"
#include "utils.h"
#include <string.h>
#include <algorithm>

#define BEGIN_ALPH_ASCII 64

int main(int argc, char* argv[])
{
    int sum = 0;
    ifstream file;
    string line;
    vector<string> names;
    vector<int> score;
    char *pch;

    if (parse_opts(argc, argv) != 0)
        exit(1);

    file.open(opt.file);
    getline(file, line);

    pch = strtok((char*)line.c_str(), ", \"");
    while (pch != NULL) {
        names.push_back(string(pch));
        pch = strtok(NULL, ", \"");
    }

    sort(names.begin(), names.end());

    for (int i = 0; i < names.size(); i++) {
        int alph_score = 0;
        for (int j = 0; j < names[i].size(); j++) {
            alph_score += names[i][j] - BEGIN_ALPH_ASCII;
            //cout << j << " | " << alph_score << " | " << (int)names[i][j]  << " | " << names[i][j] << endl;
        }
        alph_score *= i+1; 
        score.push_back(alph_score);
        //cout << i << " | " << names[i] << " | " << score[i] << endl;
        sum += alph_score;
    }

    cout << "Total: " << sum << endl;

    return 0;
}
