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
    // solution = 648

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=20
ll solve()
{
    ll result = 0;
    
    vll bigInt = { 1 };
    for (ll i = 2; i <= 100; i++)
    {
        multiplyBigInt(bigInt, i);
    }

    for (const ll& v : bigInt)
    {
        result += v;
    }

    return result;
}

void multiplyBigInt(vll& bigInt, ll factor)
{
    ll carry = 0;
    for (ll& v : bigInt)
    {
        v *= factor;
        v += carry;
        carry = v / 10;
        v = v % 10;
    }

    while (carry > 0)
    {
        ll newDigit = carry % 10;
        carry /= 10;
        bigInt.push_back(newDigit);
    }
}
