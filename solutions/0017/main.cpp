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
    // solution = 21124

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=17
ll solve()
{
    string result;

    for (ll i = 0; i < 1000; i++)
    {
        result += spellOut(i+1);
    }
    
    return result.size();
}

string spellOut(ll v)
{
    switch (v)
    {
    case 1:
        return "one";
        break;

    case 2:
        return "two";
        break;

    case 3:
        return "three";
        break;

    case 4:
        return "four";
        break;

    case 5:
        return "five";
        break;

    case 6:
        return "six";
        break;

    case 7:
        return "seven";
        break;

    case 8:
        return "eight";
        break;

    case 9:
        return "nine";
        break;

    case 10:
        return "ten";
        break;

    case 11:
        return "eleven";
        break;

    case 12:
        return "twelve";
        break;

    case 13:
        return "thirteen";
        break;

    case 14:
        return "fourteen";
        break;

    case 15:
        return "fifteen";
        break;

    case 16:
        return "sixteen";
        break;

    case 17:
        return "seventeen";
        break;

    case 18:
        return "eighteen";
        break;

    case 19:
        return "nineteen";
        break;

    case 20:
        return "twenty";
        break;

    case 30:
        return "thirty";
        break;

    case 40:
        return "forty";
        break;

    case 50:
        return "fifty";
        break;

    case 60:
        return "sixty";
        break;

    case 70:
        return "seventy";
        break;

    case 80:
        return "eighty";
        break;

    case 90:
        return "ninety";
        break;
    }

    if (v < 100)
    {
        ll tens = v / 10;
        ll units = v % 10;

        return spellOut(tens * 10) + spellOut(units);
    }
    else if (v < 1000)
    {
        ll hundreds = v / 100;
        ll remainder = v - (hundreds * 100);

        string result = spellOut(hundreds) + "hundred";
        if (remainder > 0)
        {
            result += "and" + spellOut(remainder);
        }

        return result;
    }
    else
    {
        return "onethousand";
    }
}