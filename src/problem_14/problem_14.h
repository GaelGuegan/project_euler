#ifndef PROBLEM_13
#define PROBLEM_13

#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <getopt.h>
#include <vector>

using namespace std;

const char *help =
    "Usage: [options]\n"
    "Options:\n"
    "    -l, --limit   max number for computing the collatz sequence (default: 1000000)\n"
    "    -h, --help    print help\n"
    "\n";

static struct option long_options[] =
{
    {"limit",  required_argument,  0, 'l'},
    {"help",   no_argument,        0, 'h'},
    {0, 0, 0, 0}
};

static struct opt {
    uint64_t limit;
} opt;

int parse_opts(int argc, char **argv)
{
    /* set the default values */
    opt.limit = 1000000;

    /* parse the options */
    int c;
    int opt_idx = 0;
    while (-1 != (c = getopt_long(argc, argv, "l:h",
                                  long_options, &opt_idx))) {
        switch(c) {
        case 'h':
            printf("%s", help);
            exit(0);
        case 'l':
            sscanf(optarg, "%lu", &opt.limit);
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
