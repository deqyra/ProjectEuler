#ifndef PROJECTEULER__SOLUTIONS__0013__MAIN_HPP
#define PROJECTEULER__SOLUTIONS__0013__MAIN_HPP

#include "../util.hpp"

static constexpr ull ProblemNumber = 13;

/// @brief Solves problem 13 of Project Euler.
///
/// @see https://projecteuler.net/problem=13
///
/// @return The solution for problem 13 of Project Euler.
ll solve();

vs parseBigInts(std::string s);

std::string addBigInts(std::string a, std::string b);

#endif//PROJECTEULER__SOLUTIONS__0013__MAIN_HPP
