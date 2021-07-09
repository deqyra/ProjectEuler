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
    // solution = 

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=YYYY
ll solve()
{
    ll result = 0;
    
    return result;
}