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
    // solution = 4613732

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=2
ll solve()
{
    ll result = 2;

    ll a = 1;
    ll b = 2;

    while (true)
    {
        ll tmp = a + b;
        a = b;
        b = tmp;

        if (tmp > 4000000)
        {
            break;
        }

        if (tmp % 2 == 0)
        {
            result += tmp;
        }
    }
    
    return result;
}
