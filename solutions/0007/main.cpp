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
    // solution = 104743

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=7
ll solve()
{
    ll result = 0;
    
    return nthPrime(10001);
}

ll nthPrime(int n)
{
    vll primes = { 2 };

    if (n > 1)
    {
        ll current = 3;
        while (primes.size() < n)
        {
            bool divisible = false;

            for (auto& p : primes)
            {
                if (current % p == 0)
                {
                    divisible = true;
                    break;
                }
            }

            if (!divisible)
            {
                primes.push_back(current);
            }

            current += 2;
        }
    }

    return primes.back();
}