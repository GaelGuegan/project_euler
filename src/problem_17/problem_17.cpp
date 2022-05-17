#include "problem_17.h"
#include "utils.h"
#include <string>
#include <map>

int main(int argc, char* argv[])
{
    if (parse_opts(argc, argv) != 0)
        exit(1);

    map <int, string> numbers = {
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
    {10, "ten"},
    {11, "eleven"},
    {12, "twelve"},
    {13, "thirteen"},
    {14, "fourteen"},
    {15, "fifteen"},
    {16, "sixteen"},
    {17, "seventeen"},
    {18, "eighteen"},
    {19, "nineteen"},
    {20, "twenty"},
    {30, "thirty"},
    {40, "forty"},
    {50, "fifty"},
    {60, "sixty"},
    {70, "seventy"},
    {80, "eighty"},
    {90, "ninety"},
    {100, "hundred"},
    {1000, "thousand"} };

    int total = 0;
    vector<string> total_array(1001);

    for (int i = 1; i <= opt.number; i++) {
        if (i <= 20)
            total_array[i] = numbers[i];
        else if (i > 20 && i < 100)
            total_array[i] = numbers[get_digit(i,2)*10] + numbers[get_digit(i, 1)];
        else if (i >= 100 && i < 1000) {
            if (i % 100 == 0) {
                total_array[i] = numbers[get_digit(i,3)] + numbers[100];
            } else if (i%100 <= 20){
                total_array[i] = numbers[get_digit(i,3)] + numbers[100] + "and" + numbers[i%100];
            } else if (i%100 > 20) {
                if (i % 100 != 0) {
                    total_array[i] = numbers[get_digit(i,3)] + numbers[100] + "and";
                    total_array[i] += numbers[get_digit(i,2)*10] + numbers[get_digit(i,1)];
                }
            }
        } else if (i == 1000) {
            total_array[i] = numbers[get_digit(i,4)] + numbers[1000];
        }
        total += total_array[i].size();

    }
    cout << "Result: " << total << endl;

    return 0;
}
