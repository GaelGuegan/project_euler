/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#ifndef PROBLEM_1_H_
#define PROBLEM_1_H_

#include <getopt.h>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

const char *help =
    "Usage: [options]\n"
    "Options:\n"
    "    -l, --limit     limit of computation (default: 1000)\n"
    "    -1, --div_1     divisor 1            (default: 3)\n"
    "    -2, --div_2     divisor 2            (default: 5)\n"
    "    -h, --help      print help\n"
    "\n";

static struct option long_options[] =
{
    {"limit",  required_argument,  0, 'm'},
    {"div_1",  required_argument,  0, '1'},
    {"div_2",  required_argument,  0, '2'},
    {"help",   no_argument,        0, 'h'},
    {0, 0, 0, 0}
};

static struct opt {
    int limit;
    int div_1;
    int div_2;
} opt;

int parse_opts(int argc, char **argv)
{
    /* set the default values */
    opt.limit = 1000;
    opt.div_1 = 3;
    opt.div_2 = 5;

    /* parse the options */
    int c;
    int opt_idx = 0;
    while (-1 != (c = getopt_long(argc, argv, "l:1:2:h",
                                  long_options, &opt_idx))) {
        switch (c) {
        case 'h':
            printf("%s", help);
            exit(0);
        case 'l':
            sscanf(optarg, "%i", &opt.limit);
            break;
        case 'a':
            sscanf(optarg, "%i", &opt.div_1);
            break;
        case 'b':
            sscanf(optarg, "%i", &opt.div_2);
            break;
        default:
            cerr << "Unknow option." << endl;
            exit(1);
        }
    }

    if (optind < argc) {
        cout << "non-option ARGV-elements: ";
        while (optind < argc)
            cout << argv[optind++];
        cout << endl;
    }
    return 0;
}

#endif  // PROBLEM_01_H_
