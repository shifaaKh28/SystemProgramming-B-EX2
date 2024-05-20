//email: shifaaKhatib28@gmail.com
//id: 324095702
#include "Graph.hpp"
namespace ariel
{
    Graph::Graph() {}

    bool Graph::isDirectedGraph()
    {
        return isDirected;
    }

    void Graph::setDirected(bool isdirected)
    {
        isDirected = isdirected;
    }

    size_t Graph::getNumberOfVertices()
    {
        // Return the number of vertices in the graph
        return adjMatrix.size();
    }

    int Graph::getNumberOfEdges()
    {
        int edges = 0; // Initialize the variable to count the number of edges

        // Check if the graph is undirected
        if (!isDirected)
        {
            // Iterate over each row of the adjacency matrix
            for (size_t i = 0; i < adjMatrix.size(); i++)
            {
                // Iterate over each element in the upper triangular part of the current row
                for (size_t j = i; j < adjMatrix[i].size(); j++)
                {
                    // If the element is non-zero and not on the diagonal, increment the edge count
                    if (i != j && adjMatrix[i][j] != 0)
                    {
                        edges++;
                    }
                }
            }
        }
        else
        { // If the graph is directed
            // Iterate over each row of the adjacency matrix
            for (size_t i = 0; i < adjMatrix.size(); i++)
            {
                // Iterate over each element in the current row
                for (size_t j = 0; j < adjMatrix[i].size(); j++)
                {
                    // If the element is non-zero, increment the edge count
                    if (adjMatrix[i][j] != 0)
                    {
                        edges++;
                    }
                }
            }
        }

        // Return the total number of edges in the graph
        return edges;
    }

    bool Graph::isWeightedGraph()
    {
        // Iterate over each row in the adjacency matrix
        for (size_t i = 0; i < adjMatrix.size(); i++)
        {
            // Iterate over each element in the current row
            for (size_t j = 0; j < adjMatrix[i].size(); j++)
            {
                // Check if the current element is greater than 1 or less than -1
                if (adjMatrix[i][j] > 1 || adjMatrix[i][j] < -1)
                {
                    return true;
                }
            }
        }
        return false;
    }
    int Graph::getEdgeWeight(size_t start, size_t end)
    {
        // Check if the vertices are within the valid range
        if (start >= adjMatrix.size() || end >= adjMatrix.size())
        {
            throw std::out_of_range("Vertex index out of range.");
        }

        // Return the weight of the edge from start to end
        return adjMatrix[start][end];
    }

    bool Graph::isNegativeEdge()
    {
        for (size_t i = 0; i < adjMatrix.size(); i++)
        {
            for (size_t j = 0; j < adjMatrix[i].size(); j++)
            {
                if (adjMatrix[i][j] < 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
    void Graph::loadGraph(vector<vector<int>> mat, bool isdirected)
    {
        // Check if the matrix is square
        for (size_t i = 0; i < mat.size(); ++i)
        {
            if (mat[i].size() != mat.size())
            {
                throw invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        // Check if the diagonal of the matrix is always 0
        for (size_t i = 0; i < mat.size(); ++i)
        {
            if (mat[i][i] != 0)
            {
                throw invalid_argument("Invalid graph: The diagonal of the adjacency matrix must be 0.");
            }
        }

        // Copy the provided matrix and isdirected flag to the object's members
        adjMatrix = mat;
        isDirected = isdirected;
    }
    void Graph::printGraph()
    {
        cout << "Graph with " << adjMatrix.size() << " vertices and " << getNumberOfEdges() << " edges." << endl;
    }

    /*helper method that we will use it in ALgorithms.cpp to get the neighbors of vertex in the graph*/
    vector<int> Graph::getNeighbors(size_t v)
    {
        vector<int> neighbors;
        // Check if the vertex is within the valid range
        if (v < adjMatrix.size())
        {
            // Iterate over the adjacency list of the vertex
            for (size_t i = 0; i < adjMatrix[v].size(); ++i)
            {
                // If there is an edge from 'vertex' to 'i', add 'i' to the neighbors
                if (adjMatrix[v][i] != 0)
                {
                    neighbors.push_back(i);
                }
            }
        }
        return neighbors;
    }

}
