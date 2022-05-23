/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#ifndef PROBLEM_10_H
#define PROBLEM_10_H

#include <getopt.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

const char *help =
    "Usage: [options]\n"
    "Options:\n"
    "    -l, --limit   Limit of the prime number to sum (default: 2000000)\n"
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
    opt.limit = 2000000;

    /* parse the options */
    int c;
    int opt_idx = 0;
    while (-1 != (c = getopt_long(argc, argv, "l:h",
                                  long_options, &opt_idx))) {
        switch (c) {
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
