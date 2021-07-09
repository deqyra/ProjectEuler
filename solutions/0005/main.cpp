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
    // solution = 232792560

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=5
ll solve()
{
    return scmOfFirstNaturals(20);
}

ll scmOfFirstNaturals(int largestN)
{
    if (largestN <= 2)
    {
        return largestN;
    }

    bool evenlyDivisible = false;

    ll scm = 0;
    int increment = largestN % 2 == 0 ? largestN : largestN + 1;

    while (!evenlyDivisible)
    {
        scm += increment;
        evenlyDivisible = true;

        for (int i = 3; i <= largestN; i++)
        {
            if (scm % i != 0)
            {
                evenlyDivisible = false;
                break;
            }
        }
    }

    return scm;
}
