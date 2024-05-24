/*
 * Demo program for Exercise 3.
 * Author: Benjamin Saldman.
 */

#include "Graph.hpp"
#include "Algorithms.hpp"


#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
using namespace ariel;



int main() {
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph, false);

    cout << g1; 

    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> graph1 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g2;
    g2.loadGraph(graph1, false); 

    ariel::Graph g3 = g1 + g2; // Add the two graphs together.
    cout << g3; 

    g1 *= -2; // Multiply the graph by -2.
    cout << g1; 


    ariel::Graph g4 = g1 * g2; 
    cout << g4; 

    ariel::Graph g5;
    ariel::Graph g6;

    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}};

    g5.loadGraph(graph2,false);    

        vector<vector<int>> graph3 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g6.loadGraph(graph3,false);

    // Comparison operations
    if (g5 < g6) {
        cout << "Graph g5 is less than Graph g6" << endl;
    } else if (g5 > g6) {
        cout << "Graph g5 is greater than Graph g6" << endl;
    } else {
        cout << "Graph g5 is equal to Graph g6" << endl;
    }

    return 0;
}
