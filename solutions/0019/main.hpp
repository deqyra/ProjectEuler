#ifndef PROJECTEULER__SOLUTIONS__0019__MAIN_HPP
#define PROJECTEULER__SOLUTIONS__0019__MAIN_HPP

#include "../util.hpp"

static constexpr ull ProblemNumber = 19;

/// @brief Solves problem 19 of Project Euler.
///
/// @see https://projecteuler.net/problem=19
///
/// @return The solution for problem 19 of Project Euler.
ll solve();

enum weekday
{
    monday      = 0,
    tuesday     = 1,
    wednesday   = 2,
    thursday    = 3,
    friday      = 4,
    saturday    = 5,
    sunday      = 6
};

enum month
{
    january     =  1,
    february    =  2,
    march       =  3,
    april       =  4,
    may         =  5,
    june        =  6,
    july        =  7,
    august      =  8,
    september   =  9,
    october     = 10,
    november    = 11,
    december    = 12
};

struct date
{
    char day;
    month month;
    int  year;

    bool operator==(const date& other)
    {
        return (day   == other.day)
            && (month == other.month)
            && (year  == other.year);
    }

    bool operator<(const date& other)
    {
        if (year < other.year) return true;
        if (year == other.year)
        {
            if (month < other.month) return true;
            if (month == other.month)
            {
                if (day < other.day) return true;
            }
        }

        return false;
    }

    bool operator<=(const date& other)
    {
        return (*this == other) || (*this < other);
    }

    bool operator>(const date& other)
    {
        return !(*this <= other);
    }

    bool operator>=(const date& other)
    {
        return (*this == other) || (*this > other);
    }
};

const mcc DaysInMonths = {
    { january,      31 },
    { february,     28 },   // add 1 for bissextile years
    { march,        31 },
    { april,        30 },
    { may,          31 },
    { june,         30 },
    { july,         31 },
    { august,       31 },
    { september,    30 },
    { october,      31 },
    { november,     30 },
    { december,     31 }
};

constexpr date Epoch = {1, january, 1900};

constexpr weekday EpochWeekday = monday;

bool isBissextile(int year);

int epochIndexedDay(const date& date);

weekday weekdayOfDate(const date& date);

weekday weekdayOfEpochIndexedDay(int day);

#endif//PROJECTEULER__SOLUTIONS__0019__MAIN_HPP
