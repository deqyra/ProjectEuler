#include "main.hpp"

#ifdef _WIN32
	#include <windows.h>
#endif

using namespace std;

int main(int argc, char** argv)
{
	#ifdef _WIN32
		SetConsoleOutputCP(65001);
	#endif
    
    cout << "Problem n°" << ProblemNumber << ": solving..." << endl;

    ll solution = solve();
    // solution = 171

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=19
ll solve()
{
    ll result = 0;
    
    const date start = {1, january, 1901};
    
    const date end = {31, december, 2000};

    date current = start;

    while (current <= end)
    {
        if (weekdayOfDate(current) == sunday)
        {
            result++;
        }

        current.month = (month)((int)current.month + 1);
        if ((int)current.month == 13)
        {
            current.month = january;
            current.year++;
        }
    }

    return result;
}

bool isBissextile(int year)
{
    // early return for most cases
    if (year % 4 != 0) return false;

    if ((year % 4 == 0) && (year % 100 != 0)) return true;
    if (year % 400 == 0) return true;

    return false;
}

int epochIndexedDay(const date& date)
{
    int index = 0;
    constexpr int DaysInYear = 365;
    for (int i = Epoch.year; i < date.year; i++)
    {
        index += DaysInYear;
        if (isBissextile(i))
        {
            index++;
        }
    }

    for (int i = (int)Epoch.month; i < (int)date.month; i++)
    {
        index += DaysInMonths.at((month)i);

        if ((month)i == february && isBissextile(date.year))
        {
            index++;
        }
    }

    index += date.day - Epoch.day;

    return index; 
}

weekday weekdayOfDate(const date& date)
{
    return weekdayOfEpochIndexedDay(epochIndexedDay(date));
}

weekday weekdayOfEpochIndexedDay(int day)
{
    int weekdayIndex = (day % 7) + (int)(EpochWeekday);
    if (weekdayIndex >= 7)
    {
        weekdayIndex -= 7;
    }

    return (weekday)weekdayIndex;
}
