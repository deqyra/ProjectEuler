#include "main.hpp"

#ifdef _WIN32
	#include <windows.h>
#endif

using namespace std;

constexpr ll MaxWeight = 99;

const char pyramid[] =
"75 "
"95 64 "
"17 47 82 "
"18 35 87 10 "
"20 04 82 47 65 "
"19 01 23 75 03 34 "
"88 02 77 73 07 63 67 "
"99 65 04 28 06 16 70 92 "
"41 41 26 56 83 40 80 70 33 "
"41 48 72 33 47 32 37 16 94 29 "
"53 71 44 65 25 43 91 52 97 51 14 "
"70 11 33 28 77 73 17 78 39 68 17 57 "
"91 71 52 38 17 14 91 43 58 50 27 29 48 "
"63 66 04 68 89 53 67 30 73 16 69 87 40 31 "
"04 62 98 27 23 09 70 98 73 93 38 53 60 04 23";

int main(int argc, char** argv)
{
	#ifdef _WIN32
		SetConsoleOutputCP(65001);
	#endif
    
    cout << "Problem n°" << ProblemNumber << ": solving..." << endl;

    ll solution = solve();
    // solution = 1074

    cout << "Solution: " << solution << endl;

    return 0;
}

/// @see https://projecteuler.net/problem=18
ll solve()
{
    vll ints = parseInts(pyramid);
    pyramid_graph* graph = pyramidGraphFromInts(ints);

    // find path of max weight = run dijkstra on graph of inverted weights

    invertPyramidGraphWeights(graph);
    vector<node*> reversePath = dijkstra(graph);
    
    invertPyramidGraphWeights(graph);
    ll result = pathWeight(reversePath);
    
    reversePath.clear();
    freePyramidGraph(graph);
    graph = nullptr;

    return result;
}

vll parseInts(string s)
{
    vll ints;
    ll prev = 0;
    ll index = 0;

    while ((index = s.find_first_of(' ', prev)) != string::npos)
    {
        ints.push_back(stoll(s.substr(prev, index - prev)));
        prev = index + 1;
    }
    ints.push_back(stoll(s.substr(prev, string::npos)));

    return ints;
}

pyramid_graph* pyramidGraphFromInts(const vll& ints)
{
    double dim = sqrt(ints.size() * 2);
    ll height = (ll)floor(dim);
    assert((ints.size() * 2) == (height * (height + 1)));

    pyramid_graph* graph = new pyramid_graph;
    graph->height = height;
    ll count = 0;
    for (ll i = 0; i < height; i++)
    {
        for (ll j = 0; j < (i+1); j++)
        {
            node* n = new node;
            n->id = count;
            n->value = ints[count];
            graph->nodes.push_back(n);

            if (j > 0)
            {
                ll leftParentIndex = count - i - 1;
                graph->nodes[leftParentIndex]->children.push_back(n);
            }

            if (j != i)
            {
                ll rightParentIndex = count - i;
                graph->nodes[rightParentIndex]->children.push_back(n);
            }

            count++;
        }
    }
    assert(graph->nodes.size() == ints.size());

    node* bottom = new node;
    bottom->id = count;
    bottom->value = 0;

    for (ull i = graph->nodes.size() - height; i < graph->nodes.size(); i++)
    {
        graph->nodes[i]->children.push_back(bottom);
    }
    graph->nodes.push_back(bottom);

    graph->top = graph->nodes[0];
    graph->bottom = bottom;

    return graph;
}

void freePyramidGraph(pyramid_graph* graph)
{
    graph->top = nullptr;
    graph->bottom = nullptr;
    for (auto n: graph->nodes)
    {
        n->children.clear();
        delete n;
    }
    
    graph->nodes.clear();
    delete graph;
}

void invertPyramidGraphWeights(pyramid_graph* graph)
{
    for (auto node : graph->nodes)
    {
        node->value = MaxWeight - node->value;
    }
}

std::vector<node*> dijkstra(pyramid_graph* graph)
{
    const ll MaxPathWeight = (graph->height + 1) * MaxWeight;

    // set up
    ll nodeCount = graph->nodes.size();
    bool* visited = new bool[nodeCount];
    for (ll i = 0; i < nodeCount; i++)
    {
        visited[i] = false;
    }
    ll visitedCount = 1;

    ll* distance = new ll[nodeCount];
    distance[0] = 0;
    for (ll i = 1; i < nodeCount; i++)
    {
        distance[i] = MaxPathWeight + 1;
    }

    node** previous = new node*[nodeCount];
    for (ll i = 0; i < nodeCount; i++)
    {
        previous[i] = nullptr;
    }

    // start dijkstra
    node* current = graph->top;
    while (visitedCount < nodeCount)
    {
        for (auto neighbour : current->children)
        {
            if (visited[neighbour->id])
            {
                continue;
            }

            ll newDistance = neighbour->value + distance[current->id];
            if (newDistance < distance[neighbour->id])
            {
                distance[neighbour->id] = newDistance;
                previous[neighbour->id] = current;
            }
        }

        visited[current->id] = true;
        visitedCount++;
        
        // find next node to visit
        ll smallestDistance = MaxPathWeight;
        for (ull i = 0; i < (ull)nodeCount; i++)
        {
            if (visited[i])
            {
                continue;
            }

            if (distance[i] < smallestDistance)
            {
                smallestDistance = distance[i];
                if (i < graph->nodes.size())
                {
                    current = graph->nodes[i];
                }
                else
                {
                    break;
                }
            }
        }

        // happens when destination is disjoint from source
        if (smallestDistance == MaxPathWeight)
        {
            return {};
        }
    }

    // compute path
    current = graph->bottom;
    vector<node*> reversePath = {current};

    while (current->id != graph->top->id)
    {
        current = previous[current->id];
        reversePath.push_back(current);
    }

    // clean up
    delete[] visited;
    delete[] distance;
    delete[] previous;

    return reversePath;
}

ll pathWeight(const vector<node*>& path)
{
    ll sum = 0;
    for (auto n: path)
    {
        sum += n->value;
    }

    return sum;
}
