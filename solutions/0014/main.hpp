#ifndef PROJECTEULER__SOLUTIONS__0014__MAIN_HPP
#define PROJECTEULER__SOLUTIONS__0014__MAIN_HPP

#include "../util.hpp"

static constexpr ull ProblemNumber = 14;

/// @brief Solves problem 14 of Project Euler.
///
/// @see https://projecteuler.net/problem=14
///
/// @return The solution for problem 14 of Project Euler.
ll solve();

const mllll& collatzSequenceMap(ll v);

ll indexOfLongestChain(const mllll& m, ll maxIndex);

ll nextCollatzNumber(ll v);

#endif//PROJECTEULER__SOLUTIONS__0014__MAIN_HPP
