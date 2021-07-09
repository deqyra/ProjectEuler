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
    // solution = 906609

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=4
ll solve()
{
    int maxOperand = 999;
    ll result = 0;
    
    for (int i = maxOperand; i > 0; i--)
    {
        for (int j = maxOperand; j > 0; j--)
        {
            ll product = i * j;
            if (product > result && isPalindrome(product))
            {
                result = product;
            }
        }
    }

    return result;
}

bool isPalindrome(ll n)
{
    int nDigits = (int)floor(log10(n)) + 1;
    vector<char> digits;

    for (int i = 0; i < nDigits; i++)
    {
        ll rem = (ll)(n / pow(10, i));
        digits.push_back(rem % 10);
    }

    int loopRange = (int)(ceil(nDigits / 2));
    for (int i = 0; i < loopRange; i++)
    {
        ll iMatching = digits.size() - 1 - i;
        if (digits[i] != digits[iMatching])
        {
            return false;
        }
    }

    return true;
}