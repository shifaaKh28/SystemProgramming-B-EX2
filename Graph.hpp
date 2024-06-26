#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>

using namespace std;

namespace ariel
{
    /**
     * @brief The Graph class represents a graph using an adjacency matrix.
     */
    class Graph
    {
    public:
        vector<vector<int>> adjMatrix; // Adjacency matrix representing the graph
        bool isDirected;               // Indicates whether the graph is directed

    public:
        /**
         * @brief Default constructor.
         * Initializes an empty graph.
         */
        Graph();

        /**
         * @brief Loads the graph from the given adjacency matrix.
         *
         * @param mat The adjacency matrix representing the graph.
         * @param isdirected Indicates whether the graph is directed.
         */
        void loadGraph(vector<vector<int>> mat, bool isdirected);

        /**
         * @brief Prints the adjacency matrix of the graph.
         */
        void printGraph();

        /**
         * @brief Returns the number of vertices in the graph.
         *
         * @return The number of vertices.
         */
        size_t getNumberOfVertices();

        /**
         * @brief Returns the number of edges in the graph.
         *
         * @return The number of edges.
         */
        int getNumberOfEdges();

        /**
         * @brief Checks if the graph is a weighted graph.
         *
         * @return true if the graph is weighted, false otherwise.
         */
        bool isWeightedGraph();

        /**
         * @brief Returns the weight of the edge from the start vertex to the end vertex.
         *
         * @param start The starting vertex.
         * @param end The ending vertex.
         * @return The weight of the edge from start to end, or 0 if there is no edge.
         */
        int getEdgeWeight(size_t start, size_t end);

        /**
         * @brief Checks if the graph has negative edge weights.
         *
         * @return true if the graph has negative edge weights, false otherwise.
         */
        bool isNegativeEdge();

        /**
         * @brief Checks if the graph is a directed graph.
         *
         * @return true if the graph is directed, false otherwise.
         */
        bool isDirectedGraph();

        /**
         * @brief Sets whether the graph is directed.
         */
        void setDirected(bool isdirected);

        /*get the neighbors of vertex in the graph*/
        vector<int> getNeighbors(size_t v);

        /* part2: Operator overloading*/

        // Arithmetic operators
        Graph operator+(const Graph &g) const;
        Graph &operator+=(const Graph &g);
        Graph operator+() const;

        Graph operator-(const Graph &g) const;
        Graph &operator-=(const Graph &g);
        Graph operator-() const;

        // Comparison operators
        bool operator==(const Graph &g) const;
        bool operator!=(const Graph &g) const;
        bool operator>(const Graph &g) const;
        bool operator>=(const Graph &g) const;
        bool operator<(const Graph &g) const;
        bool operator<=(const Graph &g) const;

        // Increment and decrement operators
        Graph &operator++();   // Pre-increment
        Graph operator++(int); // Post-increment
        Graph &operator--();   // Pre-decrement
        Graph operator--(int); // Post-decrement

        // Multiplication by an integer scalar
        Graph operator*(int scalar) const;
        Graph &operator*=(int scalar);

        // Graph multiplication
        Graph operator*(const Graph &other) const;

        /**
         * @brief Overloaded output stream operator for displaying the graph.
         * @param os The output stream object.
         * @param g The graph object to be displayed.
         * @return The output stream object.
         */
        friend std::ostream &operator<<(std::ostream &os, const Graph &g);
    };

} // namespace ariel

#endif // GRAPH_HPP
