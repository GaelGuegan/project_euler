#ifndef PROBLEM_12
#define PROBLEM_12

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
    "    -d, --divisors    Maximum number of divisors (default: 500)\n"
    "    -h, --help        print help\n"
    "\n";

static struct option long_options[] =
{
    {"divisors",  required_argument,  0, 'd'},
    {"help",      no_argument,        0, 'h'},
    {0, 0, 0, 0}
};

static struct opt {
    int divisors;
} opt;

int parse_opts(int argc, char **argv)
{
    /* set the default values */
    opt.divisors = 500;

    /* parse the options */
    int c;
    int opt_idx = 0;
    while (-1 != (c = getopt_long(argc, argv, "d:h",
                                  long_options, &opt_idx))) {
        switch(c) {
        case 'h':
            printf("%s", help);
            exit(0);
        case 'd':
            sscanf(optarg, "%i", &opt.divisors);
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
