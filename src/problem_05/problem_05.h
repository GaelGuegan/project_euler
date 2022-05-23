/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#ifndef PROBLEM_5
#define PROBLEM_5

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <getopt.h>

using namespace std;

const char *help =
    "Compute smallest positive number that is evenly divisible by all of the numbers from 1 to 20.\n\n"
    "Usage: [options]\n"
    "Options:\n"
    "    -m, --max_divider     limit of computation (default: 20)\n"
    "    -h, --help            print help\n"
    "\n";

static struct option long_options[] =
{
    {"max_divider",  required_argument,  0, 'm'},
    {"help",         no_argument,        0, 'h'},
    {0, 0, 0, 0}
};

static struct opt {
    int max_divider;
} opt;

int parse_opts(int argc, char **argv)
{
    /* set the default values */
    opt.max_divider = 20;

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
            sscanf(optarg, "%i", &opt.max_divider);
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
