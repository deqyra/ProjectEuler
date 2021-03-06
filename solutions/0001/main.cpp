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
    // solution = 233168

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=1
ll solve()
{
    ll result = 0;

    for (int i = 1; i < 1000; i++)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
        {
            result += i;
        }
    }

    return result;
}
