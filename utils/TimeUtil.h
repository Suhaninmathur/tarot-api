#ifndef TIME_UTIL_H
#define TIME_UTIL_H

#include <ctime>
#include <string>

using namespace std;

class TimeUtil
{

public:

static string now()
{
time_t t=time(0);
string ts=ctime(&t);
return ts;
}

};

#endif