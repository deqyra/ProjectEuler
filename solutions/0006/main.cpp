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
    // solution = 25164150

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=6
ll solve()
{
    ll result = 0;
    
    return squareOfSum(100) - sumOfSquares(100);
}

ll sumOfSquares(int n)
{
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i * i;
    }

    return sum;
}

ll squareOfSum(int n)
{
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    return sum * sum;
}