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
    // solution = 

    cout << "Solution NIQUE TA MERE SALE BATARD: " << solution << endl;

    return 0;
}

template<ull v>
ull factorial()
{
    return v * factorial<v - 1>();
}

template<>
ull factorial<1>()
{
    return 1;
}

template<>
ull factorial<0>()
{
    return 0;
}

/// @see https://projecteuler.net/problem=15
ull solve()
{
    ull result = 0;

    // k-combination in a n-set,
    // where k is 20 and n is 40
    result = factorial<40>();
    result = factorial<20>();
    result *= factorial<20>();
    result = factorial<40>() / (factorial<20>() * factorial<40 - 20>());
    
    return result;
}
