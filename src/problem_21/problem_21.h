/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#ifndef PROBLEM_21
#define PROBLEM_21

#include <getopt.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

const char *help =
    "Usage: [options]\n"
    "Options:\n"
    "    -h, --help    print help\n"
    "\n";

static struct option long_options[] =
{
    {"max",    required_argument,  0, 'm'},
    {"help",   no_argument,        0, 'h'},
    {0, 0, 0, 0}
};

static struct opt {
    int max;
} opt;

int parse_opts(int argc, char **argv)
{
    /* set the default values */
    opt.max = 1000;

    /* parse the options */
    int c;
    int opt_idx = 0;
    while (-1 != (c = getopt_long(argc, argv, "hm:",
                                  long_options, &opt_idx))) {
        switch (c) {
        case 'm':
            sscanf(optarg, "%i", &opt.max);
            // opt.max = atoi(optarg);
            break;
        case 'h':
            printf("%s", help);
            exit(0);
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
