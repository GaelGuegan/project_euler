/*************************************************************************
 * Copyright (c) 2022 Gael GUEGAN. All rights reserved.
 *
 * The computer program contained herein contains proprietary information
 * which is the property of Me.
 * The program may be used and/or copied only with the written permission
 * of Me or in accordance with the terms and conditions stipulated
 * in the agreement/contract under which the programs have been supplied.
 *************************************************************************/
#ifndef PROBLEM_19
#define PROBLEM_19

#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <getopt.h>
#include <vector>
#include <string.h>

using namespace std;

const char *help =
    "Usage: [options]\n"
    "Options:\n"
    "    -d, --day     day to compute total\n"
    "    -h, --help    print help\n"
    "\n";

static struct option long_options[] =
{
    {"day",   required_argument,  0, 'd'},
    {"help",  no_argument,        0, 'h'},
    {0, 0, 0, 0}
};

static struct opt {
    const char *day;
} opt;

int parse_opts(int argc, char **argv)
{
    /* set the default values */
    opt.day = "sunday";    
    //strcpy(opt.day, "sunday");    

    /* parse the options */
    int c;
    int opt_idx = 0;
    while (-1 != (c = getopt_long(argc, argv, "d:h",
                                  long_options, &opt_idx))) {
        switch(c) {
        case 'd':
            opt.day = optarg;
            //sscanf(optarg, "%s", &opt.day);
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
