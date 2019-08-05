#ifndef PROBLEM_6
#define PROBLEM_6

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <getopt.h>

using namespace std;

const char *help =
    "Compute difference between the sum of the squares of the first\n"
    "one hundred natural numbers and the square of the sum.\n\n"
    "Usage: [options]\n"
    "Options:\n"
    "    -m, --max_sum     max number (default: 100)\n"
    "    -h, --help        print help\n"
    "\n";

static struct option long_options[] =
{
    {"max_sum",  required_argument,  0, 'm'},
    {"help",         no_argument,        0, 'h'},
    {0, 0, 0, 0}
};

static struct opt {
    int max_sum;
} opt;

int parse_opts(int argc, char **argv)
{
    /* set the default values */
    opt.max_sum = 100;

    /* parse the options */
    int c;
    int opt_idx = 0;
    while (-1 != (c = getopt_long(argc, argv, "m:h",
                                  long_options, &opt_idx))) {
        switch(c) {
        case 'h':
            printf("%s", help);
            exit(0);
        case 'm':
            sscanf(optarg, "%i", &opt.max_sum);
            break;
        default:
            cerr << "Unknow option." << endl;
            exit(1);
        }
     }
     
    if (optind < argc)
    {
        cout << "non-option ARGV-elements: ";
        while (optind < argc)
            cout << argv[optind++];
        cout << endl;
    }
    return 0;
}

#endif
