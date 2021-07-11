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
    // solution = 76576500

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=12
ll solve()
{
    ll result = 0;
    ll n = 0;
    ll div = 0;
    mllll nFactorMap;
    while (div < 500)
    {
        n++;
        result = (n * (n + 1)) / 2;

        mllll allFactors = nFactorMap;
        mllll n1Factors = primeFactorDecompositionMap(n + 1);

        for (const auto& [f, v]: n1Factors)
        {
            if (allFactors.find(f) == allFactors.end())
            {
                allFactors[f] = v;
            }
            else
            {
                allFactors[f] += v;
            }
        }
        allFactors[2]--;
        nFactorMap = n1Factors;

        div = 1;
        for (const auto& [f, n]: allFactors)
        {
            div *= (n + 1);
        }
    }
    
    return result;
}

const vll& primesUpTo(ll v)
{
    static vll primes = {2, 3};
    for (ll i = primes.back() + 2; i <= v; i += 2)
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

mllll primeFactorDecompositionMap(ll v)
{
    mllll primeFactors;
    const vll& primes = primesUpTo(v);


    auto it = find_if(primes.crbegin(), primes.crend(), [v](ll p){return p <= v;});
    if (it == primes.crend())
    {
        return {};
    }

    ll p = *it;
    while (v > 1)
    {
        if (v % p == 0)
        {
            if (primeFactors.find(p) == primeFactors.end())
            {
                primeFactors[p] = 1;
            }
            else
            {
                primeFactors[p]++;
            }
            v /= p;
        }
        else
        {
            it++;
            p = *it;
        }
    }

    return primeFactors;
}
