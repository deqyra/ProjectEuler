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
    // solution = 837799

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=14
ll solve()
{
    const mllll& collatzMap = collatzSequenceMap(1000000);
    
    return indexOfLongestChain(collatzMap, 1000000);
}

const mllll& collatzSequenceMap(ll maxIndex)
{
    static mllll sequenceMap =
    {
        {0, 0},
        {1, 0}
    };

    for (ll i = 0; i <= maxIndex; i++)
    {
        ll start = i;
        while (sequenceMap.find(start) == sequenceMap.end())
        {
            ll next = nextCollatzNumber(start);
            sequenceMap[start] = next;
            start = next;
        }
    }

    return sequenceMap;
}

ll indexOfLongestChain(const mllll& m, ll maxIndex)
{
    static mllll lengthMap = 
    {
        {0, 0},
        {1, 1}
    };

    for (ll i = 2; i <= maxIndex; i++)
    {
        ll start = i;
        ll runningLength = 0;
        vll visitedIndices;
        
        while (lengthMap.find(start) == lengthMap.end())
        {
            runningLength++;
            visitedIndices.push_back(start);
            start = m.at(start);
        }
        runningLength += lengthMap[start];

        for (auto it = visitedIndices.begin(); it != visitedIndices.end(); it++)
        {
            lengthMap[*it] = runningLength--;
        }
    }

    ll maxLength = 0;
    ll index = 0;
    for (const auto& [c, l]: lengthMap)
    {
        if (l > maxLength)
        {
            maxLength = l;
            index = c;
        }
    }

    return index;
}

ll nextCollatzNumber(ll v)
{
    return (v % 2 == 0)
        ? v / 2
        : (3 * v) + 1;
}