#ifndef PROBLEM_11
#define PROBLEM_11

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
    "    -f, --file    Input file containing large number (default: problem_11.txt)\n"
    "    -n, --num     How many numbers to sum            (default: 4)\n"
    "    -h, --help    print help\n"
    "\n";

static struct option long_options[] =
{
    {"file",  required_argument,  0, 'f'},
    {"num",   required_argument,  0, 'n'},
    {"help",  no_argument,        0, 'h'},
    {0, 0, 0, 0}
};

static struct opt {
    const char *file;
    int num;
} opt;

int parse_opts(int argc, char **argv)
{
    /* set the default values */
    opt.file = "problem_11.txt";
    opt.num = 4;

    /* parse the options */
    int c;
    int opt_idx = 0;
    while (-1 != (c = getopt_long(argc, argv, "f:n:h",
                                  long_options, &opt_idx))) {
        switch(c) {
        case 'h':
            printf("%s", help);
            exit(0);
        case 'f':
            opt.file = optarg;
            break;
        case 'n':
            sscanf(optarg, "%i", &opt.num);
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
