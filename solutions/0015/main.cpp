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

    ull solution = solve();
    // solution = 137846528820

    cout << "Solution NIQUE TA MERE SALE BATARD: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=15
ull solve()
{
    // k-combination in a n-set:
    // n! / (k! * (n-k)!)
    //
    // Solution = do it with n = 40 and k = 20:
    // 40! / (20! * 20!) = 40!21 / 20!
    // (with a!b denoting a * a-1 * ... * b+1 * b)

    // Trick to avoid integer overflow:
    //
    // Original:
    // 40 * 39 * 38 * ... * 21 / 20 * 19 * ... * 3 * 2 * 1
    //
    // Every even factor in the numerator is twice the first factors in the denominator:
    // 40 is 20*2, 38 is 19*2, etc.
    // There are ten of those pairs, we want to remove them from both parts.
    // That means ten 2 factors need to be removed from the bottom part alongside with the first factors.
    // - 8 * 4 * 2 make it six of those 2's
    // - one more can be extracted from 10, which becomes 5
    // - one more can be extracted from 6, which becomes 3
    // - the last two cannot be extracted, so we need to reintroduce a 4 at the top
    // Result:
    // 39 * 37 * 35 * 33 * 31 * 29 * 27 * 25 * 23 * 21 * 4 / 9 * 7 * 5 * 5 * 3 * 3
    // 
    // Further cheating:
    // - 35 / 7*5 can be removed
    // - 27 / 9*3 can be removed
    // - 25 / 5   becomes a single 5  at the top
    // - 33 / 3   becomes a single 11 at the top
    //
    // And thus the whole denominator is consumed, which leaves us with the following:
    // 39 * 37 * 31 * 29 * 23 * 21 * 11 * 5 * 4
    //
    // But this is cheating so instead, the following solution is based on decomposing 
    // all factors and divisors in the expression into prime factors, which are then used
    // to recompose the result from the ground up, thus using minimal data width. 

    // k-combination in a n-set:
    // n! / (k! * (n-k)!)
    return nCombineK(40, 20);
}

ull nCombineK(ull n, ull k)
{
    if (k == 0 || k >= n)
    {
        return {};
    }

    // Empty factor map represents everything^0 = 1
    mllll primeFactors;

    // * n!
    for (ull i = n; i > 1; i--)
    {
        addPrimeFactorsToMap(primeFactors, primeFactorDecompositionMap(i));
    }

    // / k!
    for (ull i = k; i > 1; i--)
    {
        subtractPrimeFactorsFromMap(primeFactors, primeFactorDecompositionMap(i));
    }

    // / (n-k)!
    for (ull i = n-k; i > 1; i--)
    {
        subtractPrimeFactorsFromMap(primeFactors, primeFactorDecompositionMap(i));
    }

    // Post-condition of the above: primeFactors contains no negative entries

    ull result = 1;
    for (const auto& [f, n]: primeFactors)
    {
        for (ll i = 0; i < n; i++)
        {
            result *= f;
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

void addPrimeFactorsToMap(mllll& left, const mllll& right)
{
    for (const auto& [f, n]: right)
    {
        if (left.find(f) == left.end())
        {
            left[f] = n;
        }
        else
        {
            left[f] += n;
        }
    }
}

void subtractPrimeFactorsFromMap(mllll& left, const mllll& right)
{
    for (const auto& [f, n]: right)
    {
        if (left.find(f) == left.end())
        {
            left[f] = -n;
        }
        else
        {
            left[f] -= n;
        }
    }
}
