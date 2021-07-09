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
    // solution = 31875000

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=9
ll solve()
{
    ll result = 0;

    int a = 3;
    int b = 4;
    int c = 5;

    while (a + b + c != 1000)
    {
        findNextPythagoreanTriplet(a, b, c);
    }
    
    result = a * b * c;
    return result;
}

void findNextPythagoreanTriplet(int& a, int& b, int& c)
{
    int _a = a + 1;
    int _b = b;
    int _c = c;

    while ((_a * _a) + (_b * _b) != (_c * _c))
    {
        ll cSquared = _c * _c;
        ll maxASquared = cSquared / 2;
        ll aSquared = _a * _a;

        if (aSquared > maxASquared)
        {
            _a = 1;
            _b = 0;
            _c++;
            continue;
        }

        while (aSquared <= maxASquared)
        {
            ll potentialBSquared = cSquared - aSquared;
            _b = (int)sqrt(potentialBSquared);
            if (_b * _b == potentialBSquared)
            {
                a = _a;
                b = _b;
                c = _c;
                return;
            }
            
            _a++;
            aSquared = _a * _a;
        }
    }
}