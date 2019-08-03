#ifndef PROBLEM_5
#define PROBLEM_5

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <getopt.h>

using namespace std;

const char *help =
    "Usage: [options]\n"
    "Options:\n"
    "    -l, --limit     limit of computation (default: 4000000)\n"
    "    -h, --help      print help\n"
    "\n";

static struct option long_options[] =
{
    {"limit",  required_argument,  0, 'm'},
    {"help",   no_argument,        0, 'h'},
    {0, 0, 0, 0}
};

static struct opt {
    int limit;
} opt;

int parse_opts(int argc, char **argv)
{
    /* set the default values */
    opt.limit = 4000000;

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
            sscanf(optarg, "%i", &opt.limit);
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
