#ifndef PROBLEM_7
#define PROBLEM_7

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <getopt.h>
#include <vector>

using namespace std;

const char *help =
    "Usage: [options]\n"
    "Options:\n"
    "    -p, --prime    n-th prime number (default: 10001)\n"
    "    -h, --help     print help\n"
    "\n";

static struct option long_options[] =
{
    {"prime",  required_argument,  0, 'p'},
    {"help",   no_argument,        0, 'h'},
    {0, 0, 0, 0}
};

static struct opt {
    uint32_t prime;
} opt;

int parse_opts(int argc, char **argv)
{
    /* set the default values */
    opt.prime = 10001;

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
            sscanf(optarg, "%i", &opt.prime);
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
