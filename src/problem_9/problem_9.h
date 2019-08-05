#ifndef PROBLEM_9
#define PROBLEM_9

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <getopt.h>
#include <vector>
#include <string.h>

using namespace std;

const char *help =
    "Usage: [options]\n"
    "Options:\n"
    "    -p, --pythagorean_sum   Sum of the pythagorean triplet (default: 1000)\n"
    "    -h, --help              print help\n"
    "\n";

static struct option long_options[] =
{
    {"pythagorean_sum",  required_argument,  0, 'p'},
    {"help",             no_argument,        0, 'h'},
    {0, 0, 0, 0}
};

static struct opt {
    int pythagorean_sum;
} opt;

int parse_opts(int argc, char **argv)
{
    /* set the default values */
    opt.pythagorean_sum = 1000;

    /* parse the options */
    int c;
    int opt_idx = 0;
    while (-1 != (c = getopt_long(argc, argv, "p:h",
                                  long_options, &opt_idx))) {
        switch(c) {
        case 'h':
            printf("%s", help);
            exit(0);
        case 'p':
            sscanf(optarg, "%i", &opt.pythagorean_sum);
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
