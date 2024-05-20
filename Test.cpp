//email: shifaaKhatib28@gmail.com
//id: 324095702

#include <iostream>
#include <vector>

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph, false);
    CHECK(ariel::Algorithms::isConnected(g) == "The graph is connected.");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2, false);
    CHECK(ariel::Algorithms::isConnected(g) == "The graph is not connected.");

    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph3, false);
    CHECK(ariel::Algorithms::isConnected(g) == "The graph is not connected.");

    vector<vector<int>> graph4 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph4, false);
    CHECK(ariel::Algorithms::isConnected(g) == "The graph is not connected.");

    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 1, 0}};
    g.loadGraph(graph5, false);
    CHECK(ariel::Algorithms::isConnected(g) == "The graph is not connected.");
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph, false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2, false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "There is no path from 0 to 4");

    vector<vector<int>> graph3 = {
        {0, -5, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph3, true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "there is a Negative cycle in the graph.");

    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph4, false);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 2) == "There is no path from 1 to 2");

    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph5, false);
    CHECK(ariel::Algorithms::shortestPath(g, 3, 0) == "");
}

TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph, false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2, false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    // Test case 3: Graph with one edge (forming a cycle)
    vector<vector<int>> graph3 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g.loadGraph(graph3, false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    // Test case 4: Graph with multiple cycles
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0}};
    g.loadGraph(graph4, false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);

    // Test case 5: Graph with no cycles
    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    g5.loadGraph(graph5, false);
    CHECK(ariel::Algorithms::isContainsCycle(g5) == false);
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph, false);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2, false);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite");

    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3, false);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph4, false);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph5, false);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is not bipartite");

    vector<vector<int>> graph7;
    g.loadGraph(graph7, false);
    CHECK(ariel::Algorithms::isBipartite(g) == "Empty graph is bipartite");
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph, false));

    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 3, 0},
        {0, 0, 4},
        {0, 0, 1}};
    CHECK_THROWS(g.loadGraph(graph2, false));

    vector<vector<int>> graph3 = {
        {3, 1, 1},
        {1, 0, 2},
        {1, 3, 0},
        {0, 0, 1},
        {0, 0, 0}};
    CHECK_THROWS(g.loadGraph(graph3, false));
}

TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;

    // Graph with no negative cycles
    vector<vector<int>> graph1 = {
        {0, 5, 5},
        {2, 0, 3},
        {2, 2, 0}};
    g.loadGraph(graph1, false);
    CHECK(ariel::Algorithms::negativeCycle(g) == " no negative edges in the graph");

    // Graph with a negative cycle
    vector<vector<int>> graph2 = {
        {0, 1, -2},
        {1, 0, -3},
        {4, -5, 0}};
    g.loadGraph(graph2, false);
    CHECK(ariel::Algorithms::negativeCycle(g) == "there is a Negative cycle in the graph.");

    //  Graph with a negative cycle (weighted graph)
    vector<vector<int>> graph3 = {
        {0, 1, 3},
        {1, 0, -5},
        {3, -5, 0}};
    g.loadGraph(graph3, true);
    CHECK(ariel::Algorithms::negativeCycle(g) == "there is a Negative cycle in the graph.");
}