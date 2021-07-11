#ifndef PROJECTEULER__SOLUTIONS__0011__MAIN_HPP
#define PROJECTEULER__SOLUTIONS__0011__MAIN_HPP

#include "../util.hpp"

static constexpr ull ProblemNumber = 11;

/// @brief Solves problem 11 of Project Euler.
///
/// @see https://projecteuler.net/problem=11
///
/// @return The solution for problem 11 of Project Euler.
ll solve();

vll parseIntGrid(const std::string& grid, int& width, int& height);

enum Direction
{
    Horizontal,     // -
    Vertical,       // |
    Diagonal,       // \ 
    Antidiagonal    // /
};

ll largestAdjacentProductInGrid(const vll& grid, int width, int height, Direction dir, int adjacencyRange);

ll adjacentProductInGrid(const vll& grid, int width, int height, Direction dir, int index, int adjacencyRange);

int neighbourIndexOf(int index, int width, int height, Direction dir);

#endif//PROJECTEULER__SOLUTIONS__0011__MAIN_HPP
