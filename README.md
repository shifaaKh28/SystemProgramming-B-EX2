
# Graph Algorithms

## Overview
This project implements various graph algorithms, including algorithms for determining connectivity, finding shortest paths, detecting cycles, and identifying bipartite graphs.

## Files
- **Graph.hpp / Graph.cpp**: Contains the implementation of the Graph class, which represents a graph data structure. This class provides methods for managing and manipulating graphs.
- **Algorithms.hpp / Algorithms.cpp**: Implements graph algorithms such as isConnected, shortestPath, isContainsCycle, isBipartite, and negativeCycle.
- **Test.cpp**: Provides unit tests for the implemented algorithms using the doctest framework.

## Dependencies
- C++ compiler
- doctest (testing framework)

## Graph Class Methods
- **isDirectedGraph()**: Returns true if the graph is directed, false otherwise.
- **setDirected(bool isdirected)**: Sets the directed status of the graph.
- **getNumberOfVertices()**: Returns the number of vertices in the graph.
- **getNumberOfEdges()**: Returns the number of edges in the graph.
- **isWeightedGraph()**: Returns true if the graph is weighted, false otherwise.
- **getEdgeWeight(size_t start, size_t end)**: Returns the weight of the edge from start to end.
- **isNegativeEdge()**: Returns true if the graph contains negative edges, false otherwise.
- **loadGraph(vector<vector<int>> mat, bool isdirected)**: Loads the graph from an adjacency matrix and sets its directed status.
- **printGraph()**: Prints information about the graph, including the number of vertices and edges.
- **getNeighbors(size_t v)**: Returns a vector containing the neighbors of a given vertex.

## Algorithms Class Methods
- **isConnected(Graph g)**: Checks if the graph is connected.
- **isBipartite(Graph &g)**: Checks if the graph is bipartite.
- **isContainsCycle(Graph &g)**: Checks if the graph contains a cycle.
- **negativeCycle(Graph g)**: Checks if the graph contains a negative cycle.
- **shortestPath(Graph g, size_t start, size_t end)**: Finds the shortest path between two vertices in the graph.
