#ifndef PROJECTEULER__SOLUTIONS__0015__MAIN_HPP
#define PROJECTEULER__SOLUTIONS__0015__MAIN_HPP

#include "../util.hpp"

static constexpr ull ProblemNumber = 15;

/// @brief Solves problem 15 of Project Euler.
///
/// @see https://projecteuler.net/problem=15
///
/// @return The solution for problem 15 of Project Euler.
ull solve();

ull nCombineK(ull k, ull n);

const vll& primesUpTo(ll n);

mllll primeFactorDecompositionMap(ll n);

void addPrimeFactorsToMap(mllll& left, const mllll& right);

void subtractPrimeFactorsFromMap(mllll& left, const mllll& right);

#endif//PROJECTEULER__SOLUTIONS__0015__MAIN_HPP
