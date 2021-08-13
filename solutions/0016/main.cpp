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
    // solution = 1366

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=16
ll solve()
{
    ll result = 0;

    string sResult = "1";
    for (ll i = 0; i < 1000; i++)
    {
        sResult = addBigInts(sResult, sResult);
    }

    for (const char& c : sResult)
    {
        result += c - '0';
    }
    
    return result;
}

string addBigInts(string a, string b)
{
    ll size = max(a.size(), b.size()) + 1;
    string result(size, '0');

    char carry = 0;
    for (ll i = 0; i < size; i++)
    {
        ll aIndex = a.size() - 1 - i;
        char operandA = 0;
        if (aIndex >= 0)
        {
            operandA = a[aIndex] - '0';
        }

        ll bIndex = b.size() - 1 - i;
        char operandB = 0;
        if (bIndex >= 0)
        {
            operandB = b[bIndex] - '0';
        }
        
        ll resIndex = size - 1 - i;
        result[resIndex] = operandA + operandB + carry;
        carry = 0;
        if (result[resIndex] >= 10)
        {
            result[resIndex] -= 10;
            carry = 1;
        }
        result[resIndex] += '0';
    }

    if (result[0] == '0')
    {
        result = result.substr(1, string::npos);
    }

    return result;
}
