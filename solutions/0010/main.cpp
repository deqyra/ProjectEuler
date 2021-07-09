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
    // solution = 142913828922

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=10
ll solve()
{
    ll result = 0;
    
    vll primes = primesUpTo(2000000);

    for (auto& n : primes)
    {
        result += n;
    }

    return result;
}

vll primesUpTo(ll n)
{
    vll primes;

    for (ll i = 2; i <= n; i++)
    {
        bool divisible = false;

        ll maxDivisor = (ll)sqrt(i);
        for (auto& p : primes)
        {
            if (p > maxDivisor)
            {
                break;
            }

            if (i % p == 0)
            {
                divisible = true;
                break;
            }
        }

        if (!divisible)
        {
            primes.push_back(i);
        }
    }

    return primes;
}
