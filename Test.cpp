// //email: shifaaKhatib28@gmail.com
// //id: 324095702
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1, false);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2, false);

    ariel::Graph g3 = g1 + g2;

    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};

    // Check if the adjacency matrices match
    CHECK(g3.adjMatrix == expectedGraph);

    // Test case 2: Graph addition with different sizes
    SUBCASE("Graph addition with different sizes")
    {
        ariel::Graph g3;
        ariel::Graph g4;

        // Define adjacency matrices for the graphs
        vector<vector<int>> matrix1 = {
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 0}};
        vector<vector<int>> matrix2 = {
            {0, 1, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 0, 1},
            {0, 0, 1, 0}};

        // Load graphs with adjacency matrices
        g3.loadGraph(matrix1, false);
        g4.loadGraph(matrix2, false);

        // Check if attempting to add graphs of different sizes throws an exception
        CHECK_THROWS(g3 + g4);
    }
}
TEST_CASE("Subtraction of Graphs")
{
    // Create Graph 1
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1, false);

    // Create Graph 2
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 0, 1},
        {0, 0, 0},
        {1, 0, 0}};
    g2.loadGraph(graph2, false);

    // Subtract Graph 2 from Graph 1
    ariel::Graph result = g1 - g2;

    // Check the result
    vector<vector<int>> expected_result = {
        {0, 1, -1},
        {1, 0, 1},
        {-1, 1, 0}};
    for (size_t i = 0; i < expected_result.size(); ++i)
    {
        for (size_t j = 0; j < expected_result[i].size(); ++j)
        {
            CHECK(result.adjMatrix[i][j] == expected_result[i][j]);
        }
    }
}

TEST_CASE("Unary Plus Operator")
{
    SUBCASE("Unary Plus Operator Test Case 1")
    {
        // Define an adjacency matrix for the graph
        vector<vector<int>> graphMatrix = {
            {0, 1, 0},
            {1, 0, -1},
            {0, -1, 0}};

        // Create a graph and load the adjacency matrix
        ariel::Graph g;
        g.loadGraph(graphMatrix, false);

        // Apply the unary plus operator to the graph
        ariel::Graph result = +g;

        // Check if the resulting graph has the same adjacency matrix as the original graph
        CHECK(result.adjMatrix == graphMatrix);

        // Check if both the original and resulting graphs are connected
        string gConnected = ariel::Algorithms::isConnected(g);
        string resultConnected = ariel::Algorithms::isConnected(result);
        CHECK(gConnected == resultConnected);

        string gshortestPath = ariel::Algorithms::shortestPath(g,0,3);
        string resultshortestPath = ariel::Algorithms::shortestPath(result,0,3);
        CHECK(gshortestPath == resultshortestPath);

    }


    SUBCASE("Unary Plus Operator Test Case 2")
    {
        // Define an adjacency matrix for the graph
        vector<vector<int>> graphMatrix = {
            {0, -1, 0},
            {-1, 0, 1},
            {0, 1, 0}};

        // Create a graph and load the adjacency matrix
        ariel::Graph g;
        g.loadGraph(graphMatrix, false);

        // Apply the unary plus operator to the graph
        ariel::Graph result = +g;

        // Check if the resulting graph has the same adjacency matrix as the original graph
        CHECK(result.adjMatrix == graphMatrix);
    }

    SUBCASE("Unary Plus Operator Test Case 3")
    {
        // Define an adjacency matrix for the graph
        vector<vector<int>> graphMatrix = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};

        // Create a graph and load the adjacency matrix
        ariel::Graph g;
        g.loadGraph(graphMatrix, false);

        // Apply the unary plus operator to the graph
        ariel::Graph result = +g;

        // Check if the resulting graph has the same adjacency matrix as the original graph
        CHECK(result.adjMatrix == graphMatrix);
    }
}

TEST_CASE("Test unary minus operator")
{
    // Create a graph with some edges
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}};
    g.loadGraph(graph, false);

    // Apply the unary minus operator
    ariel::Graph negatedGraph = -g;

    // Check that the weights of the edges in the original graph are negated in the result graph
    CHECK(negatedGraph.adjMatrix[0][0] == 0);
    CHECK(negatedGraph.adjMatrix[0][1] == -1);
    CHECK(negatedGraph.adjMatrix[0][2] == -2);
    CHECK(negatedGraph.adjMatrix[1][0] == -1);
    CHECK(negatedGraph.adjMatrix[1][1] == 0);
    CHECK(negatedGraph.adjMatrix[1][2] == -3);
    CHECK(negatedGraph.adjMatrix[2][0] == -2);
    CHECK(negatedGraph.adjMatrix[2][1] == -3);
    CHECK(negatedGraph.adjMatrix[2][2] == 0);
}

TEST_CASE("Test operator+=")
{
    ariel::Graph g1;
    ariel::Graph g2;

    // Test case 1: Add two graphs with the same size adjacency matrices
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1, false);

    vector<vector<int>> graph2 = {
        {0, 0, 1},
        {0, 0, 0},
        {1, 0, 0}};
    g2.loadGraph(graph2, false);

    g1 += g2;
    CHECK(g1.adjMatrix == vector<vector<int>>{
        {0, 1, 1}, 
        {1, 0, 1}, 
        {1, 1, 0}});
}

TEST_CASE("Test operator-=")
{
    ariel::Graph g1;
    ariel::Graph g2;

    // Test case 1: Subtract one graph from another with the same size adjacency matrices
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1, false);

    vector<vector<int>> graph2 = {
        {0, 0, 1},
        {0, 0, 0},
        {1, 0, 0}};
    g2.loadGraph(graph2, false);

    g1 -= g2;
    CHECK(g1.adjMatrix == vector<vector<int>>{{0, 1, -1}, {1, 0, 1}, {-1, 1, 0}});
}
TEST_CASE("Test increment and decrement operators") {
    SUBCASE("Test pre-increment operator") {
        // Case 1: Initial weights: {1, 2, 3}, {2, 1, 4}, {3, 4, 1}
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
            {0, 0, 3},
            {2, 0, 4},
            {3, 4, 0}};
        g1.loadGraph(graph1, false);

        // Pre-increment operator
        ++g1;

        // Check if all edge weights have been incremented by 1
        vector<vector<int>> expected1 = {
            {0, 1, 4},
            {3, 0, 5},
            {4, 5, 0}};
        for (size_t i = 0; i < graph1.size(); ++i) {
            for (size_t j = 0; j < graph1[i].size(); ++j) {
                CHECK(g1.adjMatrix[i][j] == expected1[i][j]);
            }
        }
    }

    SUBCASE("Test post-increment operator") {
        // Create a graph
        ariel::Graph g;
        vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g.loadGraph(graph, false);

        // Apply post-increment operator
        ariel::Graph result = g++;

        // Expected result after post-increment
        vector<vector<int>> expectedGraph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};

        // Check if the adjacency matrices of result and expectedGraph match
        CHECK(result.adjMatrix == expectedGraph);
    }

    SUBCASE("Test pre-decrement operator") {
        // Create a graph
        ariel::Graph g;
        vector<vector<int>> graph = {
            {0, 2, 1},
            {2, 0, 2},
            {1, 2, 0}};
        g.loadGraph(graph, false);

        // Apply pre-decrement operator
        --g;

        // Expected result after pre-decrement
        vector<vector<int>> expectedGraph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};

        // Check if the adjacency matrices match
        CHECK(g.adjMatrix == expectedGraph);
    }

    SUBCASE("Test post-decrement operator") {
        // Create a graph
        ariel::Graph g;
        vector<vector<int>> graph = {
            {0, 2, 1},
            {2, 0, 2},
            {1, 2, 0}};
        g.loadGraph(graph, false);

        // Apply post-decrement operator
        ariel::Graph result = g--;

        // Expected result after post-decrement
        vector<vector<int>> expectedGraph = {
            {0, 2, 1},
            {2, 0, 2},
            {1, 2, 0}};

        // Check if the adjacency matrices of result and expectedGraph match
        CHECK(result.adjMatrix == expectedGraph);
    }
}
TEST_CASE("Test scalar multiplication operator*")
{
    // Create a graph
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph, false);

    // Multiply the graph by a scalar
    ariel::Graph result = g * 3;

    // Check if the resulting graph has the correct edge weights
    vector<vector<int>> expectedGraph = {
        {0, 3, 0},
        {3, 0, 3},
        {0, 3, 0}};
    CHECK(result.adjMatrix == expectedGraph);
}

TEST_CASE("Test scalar multiplication operator*=")
{
    // Create a graph
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph, false);

    // Multiply the graph by a scalar in place
    g *= 3;

    // Check if the graph has been modified correctly
    vector<vector<int>> expectedGraph = {
        {0, 3, 0},
        {3, 0, 3},
        {0, 3, 0}};
    CHECK(g.adjMatrix == expectedGraph);
}

TEST_CASE("Test graph multiplication")
{
    // Test case 1
    {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g1.loadGraph(graph1, false);

        ariel::Graph g2;
        vector<vector<int>> graph2 = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
        g2.loadGraph(graph2, false);

        ariel::Graph g4 = g1 * g2;

        vector<vector<int>> expectedGraph1 = {
            {0, 0, 2},
            {1, 0, 1},
            {1, 0, 0}};
        // Check the result matrix element by element
        CHECK(g4.adjMatrix == expectedGraph1);
    }

    // Test case 3: Multiplying graph by zero matrix
    {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
        g1.loadGraph(graph1, false);

        ariel::Graph g2;
        vector<vector<int>> graph2 = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
        g2.loadGraph(graph2, false);

        ariel::Graph g6 = g1 * g2;

        vector<vector<int>> expectedGraph3 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
        // Check the result matrix element by element
        CHECK(g6.adjMatrix == expectedGraph3);
    }
}

TEST_CASE("Test graph == operator")
{
    // Test case 1: Equal graphs
    {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g1.loadGraph(graph1, false);

        ariel::Graph g2;
        vector<vector<int>> graph2 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g2.loadGraph(graph2, false);

        CHECK(g1 == g2);
    }
}
TEST_CASE("Test graph != operator")
{
    // Test case 1: Equal graphs
    {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g1.loadGraph(graph1, false);

        ariel::Graph g2;
        vector<vector<int>> graph2 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g2.loadGraph(graph2, false);

        CHECK_FALSE(g1 != g2);
    }

    // Test case 2: Different graphs
    {
        ariel::Graph g1;
        vector<vector<int>> graph1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
        g1.loadGraph(graph1, false);

        ariel::Graph g2;
        vector<vector<int>> graph2 = {
            {0, 1, 1},
            {1, 0, 2},
            {1, 2, 0}};
        g2.loadGraph(graph2, false);

        CHECK(g1 != g2);
    }
}

TEST_CASE("Test greater-than operator")
{
    // Create two graphs
    ariel::Graph g1, g2;
    // Load adjacency matrices
    vector<vector<int>> matrix1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> matrix2 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g1.loadGraph(matrix1, false);
    g2.loadGraph(matrix2, false);

    // g2 contains g1, so g2 is not greater than g1
    CHECK((g1 > g2) == true);


    // g1 contains g2, so g1 is greater than g2
    CHECK((g2 > g1) == false);
}

TEST_CASE("Test less-than operator")
{
    // Create two graphs
    ariel::Graph g1, g2;
    // Load adjacency matrices
    vector<vector<int>> matrix1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> matrix2 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g1.loadGraph(matrix1, false);
    g2.loadGraph(matrix2, false);

    // Check less-than operator
    // g2 contains g1, so g2 is not less than g1
    CHECK((g1 < g2) == false);

    // g1 contains g2, so g1 is less than g2
    CHECK((g2 < g1) == true);

    CHECK_FALSE(ariel::Algorithms::isBipartite(g1) == ariel::Algorithms::isBipartite(g2));

    // Check if g1 and g2 are connected
    CHECK(ariel::Algorithms::isConnected(g1) == "The graph is connected.");
    CHECK(ariel::Algorithms::isConnected(g2) == "The graph is not connected.");
}

TEST_CASE("Test <= operator")
{
    // Create two graphs
    ariel::Graph g1, g2;
    // Load adjacency matrices
    vector<vector<int>> matrix1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> matrix2 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g1.loadGraph(matrix1, false);
    g2.loadGraph(matrix2, false);

    // g2 contains g1, so g2 is not less than or equal to g1
    CHECK_FALSE(g1 <= g2);

    // g1 is equal to itself
    CHECK(g1 <= g1);
}

TEST_CASE("Test >= operator")
{
    // Create two graphs
    ariel::Graph g1, g2;
    // Load adjacency matrices
    vector<vector<int>> matrix1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> matrix2 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    g1.loadGraph(matrix1, false);
    g2.loadGraph(matrix2, false);

    // g2 contains g1, so g1 is not greater than or equal to g2
    CHECK(g1 >= g2);

    // g1 contains g2, so g2 is greater than or equal to g1
    CHECK(g2 <= g1);

    // g1 is equal to itself
    CHECK(g1 >= g1);

    // Check if g1 and g2 have negative cycles
    CHECK_FALSE(ariel::Algorithms::negativeCycle(g1) == ariel::Algorithms::negativeCycle(g2));

    // Check shortest paths in g1
    CHECK(ariel::Algorithms::shortestPath(g1, 0, 2) == "0->1->2");
}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1, false);

    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph5, false);

    CHECK_THROWS(g5 * g1);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph6 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph6, false);

    CHECK_THROWS(g1 + g6);
}
