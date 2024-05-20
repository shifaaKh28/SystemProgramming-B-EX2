#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include "Graph.hpp"
#include <limits>
#include <climits>
#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;
namespace ariel
{
    namespace Algorithms
    {
        /**
         * @brief Determines if the graph is connected.
         *
         * @param g The graph to check.
         * @return A string indicating whether the graph is connected.
         */
        string isConnected(Graph g);

        /**
         * @brief Determines if the graph is bipartite.
         *
         * @param g The graph to check.
         * @return A string indicating whether the graph is bipartite.
         */
        string isBipartite(Graph &g);

        /**
         * @brief Finds the shortest path between two vertices in the graph.
         *
         * @param g The graph.
         * @param start The starting vertex.
         * @param end The ending vertex.
         * @return A string representing the shortest path between the start and end vertices.
         */
        string shortestPath(Graph g, size_t start, size_t end);

        /**
         * @brief Checks if the graph contains a cycle.
         *
         * @param g The graph to check.
         * @return true if the graph contains a cycle, false otherwise.
         */
        bool isContainsCycle(Graph &g);

        /**
         * @brief Finds a negative cycle in the graph.
         *
         * @param g The graph to search for a negative cycle.
         * @return A string indicating whether a negative cycle is found or not.
         */
        string negativeCycle(Graph g);

    } // namespace Algorithms
} // namespace ariel
#endif // ALGORITHMS_HPP