// email: shifaaKhatib28@gmail.com
// id: 324095702
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

    /*part 2: operator overloading*/
    Graph Graph::operator+(const Graph &g) const
    {
        if (adjMatrix.size() != g.adjMatrix.size())
        {
            throw invalid_argument("Graphs must be of the same size to add.");
        }

        Graph result; // Create a new graph object to store the result

        // Initialize the adjacency matrix of the result graph with the same size as the current graph's adjacency matrix,
        // and fill it with zeros.
        result.adjMatrix = vector<vector<int>>(adjMatrix.size(), vector<int>(adjMatrix.size(), 0));
        result.isDirected = isDirected; // Assuming both graphs have the same direction property

        for (size_t i = 0; i < adjMatrix.size(); i++)
        {
            for (size_t j = 0; j < adjMatrix[i].size(); ++j)
            {
                result.adjMatrix[i][j] = adjMatrix[i][j] + g.adjMatrix[i][j];
            }
        }

        return result;
    }

    Graph Graph::operator-(const Graph &g) const
    {
        if (adjMatrix.size() != g.adjMatrix.size())
        {
            throw invalid_argument("Graphs must be of the same size to subtract.");
        }

        Graph result; // Create a new graph object to store the result
        result.adjMatrix = vector<vector<int>>(adjMatrix.size(), vector<int>(adjMatrix.size(), 0));
        result.isDirected = isDirected; // Assuming both graphs have the same direction property

        for (size_t i = 0; i < adjMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjMatrix[i].size(); ++j)
            {
                result.adjMatrix[i][j] = adjMatrix[i][j] - g.adjMatrix[i][j];
            }
        }

        return result;
    }

    Graph Graph::operator+() const
    {
        // Create a copy of the current graph
        Graph result = *this;
        return result;
    }

    Graph Graph::operator-() const
    {
        Graph result; // Create a new graph object to store the result

        // Initialize the adjacency matrix of the result graph with the same size as the current graph's adjacency matrix
        // and fill it with zeros.
        result.adjMatrix = vector<vector<int>>(adjMatrix.size(), vector<int>(adjMatrix.size(), 0));
        result.isDirected = isDirected; // Assuming both graphs have the same direction property

        // Negate the weights of the edges in the adjacency matrix
        for (size_t i = 0; i < adjMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjMatrix[i].size(); ++j)
            {
                result.adjMatrix[i][j] = -adjMatrix[i][j];
            }
        }

        // Return the result graph
        return result;
    }

    Graph &Graph::operator+=(const Graph &g)
    {
        if (adjMatrix.size() != g.adjMatrix.size())
        {
            throw invalid_argument("Graphs must be of the same size to add.");
        }

        for (size_t i = 0; i < adjMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjMatrix[i].size(); ++j)
            {
                adjMatrix[i][j] += g.adjMatrix[i][j];
            }
        }

        return *this; // Return a reference to the modified object
    }

    Graph &Graph::operator-=(const Graph &g)
    {
        if (adjMatrix.size() != g.adjMatrix.size())
        {
            throw invalid_argument("Graphs must be of the same size to add.");
        }

        for (size_t i = 0; i < adjMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjMatrix[i].size(); ++j)
            {
                adjMatrix[i][j] -= g.adjMatrix[i][j];
            }
        }

        return *this; // Return a reference to the modified object
    }

    Graph &Graph::operator++()
    {
        for (size_t i = 0; i < adjMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjMatrix[i].size(); ++j)
            {
                if (i != j)
                {
                    ++adjMatrix[i][j]; // Increment non-diagonal elements by 1
                }
            }
        }
        return *this;
    }

    Graph Graph::operator++(int)
    {
        // Create a copy of the current graph
        Graph copy(*this);
        // Increment the current graph using the pre-increment operator
        ++(*this);
        // Return the copy of the graph as it was before the increment operation
        return copy;
    }

    Graph &Graph::operator--()
    {
        for (size_t i = 0; i < adjMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjMatrix[i].size(); ++j)
            {
                if (i != j)
                {
                    --adjMatrix[i][j]; // Increment non-diagonal elements by 1
                }
            }
        }
        return *this;
    }

    Graph Graph::operator--(int)
    {
        // Create a copy of the current graph
        Graph copy(*this);
        // Increment the current graph using the pre-increment operator
        --(*this);
        // Return the copy of the graph as it was before the increment operation
        return copy;
    }

    Graph Graph::operator*(int scalar) const
    {
        Graph result(*this); // Create a copy of the current graph

        // Multiply each edge weight by the scalar
        for (size_t i = 0; i < result.adjMatrix.size(); ++i)
        {
            for (size_t j = 0; j < result.adjMatrix[i].size(); ++j)
            {
                result.adjMatrix[i][j] *= scalar;
            }
        }

        return result;
    }
    Graph &Graph::operator*=(int scalar)
    {
        for (size_t i = 0; i < adjMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjMatrix[i].size(); ++j)
            {
                adjMatrix[i][j] *= scalar;
            }
        }
        return *this;
    }

    Graph Graph::operator*(const Graph &g) const
    {
        // Check if the sizes of the two graphs are the same
        if (adjMatrix.size() != g.adjMatrix.size())
        {
            throw invalid_argument("Graphs must be of the same size to multiply.");
        }

        // Initialize result graph with the same size
        Graph result(*this);

        // Perform matrix multiplication
        for (size_t i = 0; i < adjMatrix.size(); i++)
        {
            for (size_t j = 0; j < adjMatrix.size(); j++)
            {
                // Initialize result element to 0
                result.adjMatrix[i][j] = 0;

                // Calculate the value for the element result[i][j]
                for (size_t k = 0; k < adjMatrix.size(); k++)
                {
                    result.adjMatrix[i][j] += this->adjMatrix[i][k] * g.adjMatrix[k][j];
                }

                // Ensure the diagonal elements are zero
                if (i == j)
                {
                    result.adjMatrix[i][j] = 0;
                }
            }
        }
        return result;
    }

    bool Graph::operator==(const Graph &g) const
    {
        // Check if the sizes of the two adjacency matrices are the same
        if (adjMatrix.size() != g.adjMatrix.size())
        {
            return false;
        }

        // Compare each element of the adjacency matrices
        for (size_t i = 0; i < adjMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjMatrix[i].size(); ++j)
            {
                if (adjMatrix[i][j] != g.adjMatrix[i][j])
                {
                    return false; // If any element differs, the graphs are not equal
                }
            }
        }

        return true; // All elements are the same, the graphs are equal
    }

    bool Graph::operator!=(const Graph &g) const
    {
        return !(*this == g);
    }

    bool isContained(const Graph &g1, const Graph &g2)
    {
        // Checking if g1 is contained in g2, we'll go over g1 and check if all the values are in g2
        for (size_t i = 0; i < g1.adjMatrix.size(); i++)
        {
            for (size_t j = 0; j < g1.adjMatrix.size(); j++)
            {
                if (g1.adjMatrix[i][j] != 0 && g2.adjMatrix[i][j] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool Graph::operator>(const Graph &g) const
    {
        // Use the helper function to check if the current graph (this) is contained in g
        if (isContained(*this, g))
        {
            return false; // If this is contained in g, then this is not greater than g
        }

        // Use the helper function to check if g is contained in the current graph (this)
        if (isContained(g, *this))
        {
            return true; // If g is contained in this, then this is greater than g
        }

        // If neither graph is contained in the other, compare the number of edges
        int edgesThis = 0;
        int edgesOther = 0;
        for (size_t i = 0; i < adjMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjMatrix[i].size(); ++j)
            {
                edgesThis += (adjMatrix[i][j] != 0) ? 1 : 0;
                edgesOther += (g.adjMatrix[i][j] != 0) ? 1 : 0;
            }
        }

        if (edgesThis != edgesOther)
        {
            return edgesThis > edgesOther;
        }

        // If the number of edges is the same, compare the magnitudes of the adjacency matrices
        int magnitudeThis = 0;
        int magnitudeOther = 0;
        for (size_t i = 0; i < adjMatrix.size(); ++i)
        {
            for (size_t j = 0; j < adjMatrix[i].size(); ++j)
            {
                magnitudeThis += adjMatrix[i][j];
                magnitudeOther += g.adjMatrix[i][j];
            }
        }
        return magnitudeThis > magnitudeOther;
    }

    bool Graph::operator<(const Graph &g) const
    {
        // Use the greater-than operator to check if other is greater than *this
        return g > *this;
    }

    bool Graph::operator<=(const Graph &g) const
    {
        return !(*this > g);
    }

    bool Graph::operator>=(const Graph &g) const
    {
        return !(*this < g);
    }
}
