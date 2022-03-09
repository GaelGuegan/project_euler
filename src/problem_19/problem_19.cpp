#include "problem_19.h"
#include "Date.h"
#include "utils.h"
#include <string.h>
#include <list>

int main(int argc, char* argv[])
{
    list<Date> dates;
    Date date0 = Date(01, 01, 1900, "Monday");

    if (parse_opts(argc, argv) != 0)
        exit(1);

    dates.push_back(date0);
/*
remplir list :
struct date {
	int day, month, year;
	string dayname;
}
list[0] = date = 01 01 1900 monday

while year <= 2000
push
d++
if d == 31 && (m == 01 || m == 03 ...)
 d = 0
 m++
if m == 13
 m = 1
 y++

01/01/1900 : M T W T F S S ...
30/01/1900 :
28[29]/02
31/03
30/04
31/05
30/06
31/07
31/08
30/09
31/10
30/11
31/12
*/

    cout << "Result: " << endl;

    return 0;
}
