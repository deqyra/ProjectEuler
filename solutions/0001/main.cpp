#include "main.hpp"

#include <iostream>

#ifdef _WIN32
	#include <windows.h>
#endif

int main(int argc, char** argv)
{
	#ifdef _WIN32
		SetConsoleOutputCP(65001);
	#endif
    
    std::cout << "Problem n°" << ProblemNumber << ": solving..." << std::endl;

    long long int solution = solve();

    std::cout << "Solution: " << solution << std::endl;

    return 0;
}

long long int solve()
{
    return 0;
}
