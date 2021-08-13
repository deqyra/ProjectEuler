#ifndef PROJECTEULER__SOLUTIONS__0018__MAIN_HPP
#define PROJECTEULER__SOLUTIONS__0018__MAIN_HPP

#include "../util.hpp"

static constexpr ull ProblemNumber = 18;

/// @brief Solves problem 18 of Project Euler.
///
/// @see https://projecteuler.net/problem=18
///
/// @return The solution for problem 18 of Project Euler.
ll solve();

vll parseInts(std::string s);

struct node
{
    ll id;
    std::vector<node*> children;
    ll value;
};

struct pyramid_graph
{
    std::vector<node*> nodes;
    node* top;
    node* bottom;
    ll height;
};

pyramid_graph* pyramidGraphFromInts(const vll& ints);

void freePyramidGraph(pyramid_graph* graph);

void invertPyramidGraphWeights(pyramid_graph* graph);

std::vector<node*> dijkstra(pyramid_graph* graph);

ll pathWeight(const std::vector<node*>& path);

#endif//PROJECTEULER__SOLUTIONS__0018__MAIN_HPP
