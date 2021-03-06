#ifndef PROBLEM_16
#define PROBLEM_16

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
    "    -n, --num     number to power (default: 2)\n"
    "    -p, --power   power           (default: 1000\n"
    "    -h, --help    print help\n"
    "\n";

static struct option long_options[] =
{
    {"num",    required_argument,  0, 'n'},
    {"power",  required_argument,  0, 'p'},
    {"help",   no_argument,        0, 'h'},
    {0, 0, 0, 0}
};

static struct opt {
    int num;
    int power;
} opt;

int parse_opts(int argc, char **argv)
{
    /* set the default values */
    opt.num = 2;
    opt.power = 1000;

    /* parse the options */
    int c;
    int opt_idx = 0;
    while (-1 != (c = getopt_long(argc, argv, "n:p:h",
                                  long_options, &opt_idx))) {
        switch(c) {
        case 'h':
            printf("%s", help);
            exit(0);
        case 'n':
            sscanf(optarg, "%i", &opt.num);
            break;
        case 'p':
            sscanf(optarg, "%i", &opt.power);
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
