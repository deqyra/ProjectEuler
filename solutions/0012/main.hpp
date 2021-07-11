#ifndef PROJECTEULER__SOLUTIONS__0012__MAIN_HPP
#define PROJECTEULER__SOLUTIONS__0012__MAIN_HPP

#include "../util.hpp"

static constexpr ull ProblemNumber = 12;

/// @brief Solves problem 12 of Project Euler.
///
/// @see https://projecteuler.net/problem=12
///
/// @return The solution for problem 12 of Project Euler.
ll solve();

ll nthTriangularNumber(ll n);

ll nDivisors(ll v);

const vll& primesUpTo(ll n);

mllll primeFactorDecompositionMap(ll n);

vll primeFactorDecomposition(ll n);

#endif//PROJECTEULER__SOLUTIONS__0012__MAIN_HPP
