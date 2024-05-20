//email: shifaaKhatib28@gmail.com
//id: 324095702

#include "Graph.hpp"
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

namespace ariel
{
    namespace Algorithms
    {

        void dfs_traverse(Graph g, size_t v, vector<bool> &visited)
        {
            // Mark the current vertex as visited
            visited[v] = true;
            // Get the neighbors of the current vertex
            vector<int> neighbors = g.getNeighbors(v);
            // Visit each neighbor of the current vertex recursively
            for (size_t i = 0; i < neighbors.size(); ++i)
            {
                size_t curr_neighbor = static_cast<size_t>(neighbors[i]);
                if (!visited[curr_neighbor])
                {
                    dfs_traverse(g, curr_neighbor, visited);
                }
            }
        }

        string isConnected(Graph g)
        {
            // Check if the graph is directed
            if (!g.isDirectedGraph())
            {
                // Initialize a vector to track visited vertices
                vector<bool> visited(g.getNumberOfVertices(), false);

                // Perform depth-first search starting from vertex 0
                dfs_traverse(g, 0, visited);

                // Check if all vertices were visited
                for (size_t i = 0; i < visited.size(); ++i)
                {
                    if (!visited[i])
                    {
                        return "The graph is not connected.";
                    }
                }
                // If all vertices were visited, return connected
                return "The graph is connected.";
            }
            else
            {
                // For directed graphs, perform depth-first search from each vertex
                vector<bool> visited(g.getNumberOfVertices(), false);
                dfs_traverse(g, 0, visited);

                // Check if all vertices were visited
                for (size_t i = 0; i < visited.size(); ++i)
                {
                    if (!visited[i])
                    {
                        return "The graph is not connected.";
                    }
                }
                // If all vertices were visited, return connected
                return "The graph is connected.";
            }
        }

        string isBipartite(Graph &g)
        {
            size_t n = g.getNumberOfVertices();
            if (n == 0)
            {
                return "Empty graph is bipartite";
            }

            // Perform BFS starting from the first vertex
            queue<size_t> q;          // Queue to store vertices
            vector<int> color(n, -1); // Color array to mark the vertices
            vector<size_t> A, B;      // Vectors to store the two sets

            color[0] = 0;
            A.push_back(0); // Start vertex 0 in set 1
            q.push(0);

            while (!q.empty())
            {
                size_t u = q.front();
                q.pop();

                vector<int> neighbors = g.getNeighbors(u);
                for (size_t i = 0; i < neighbors.size(); ++i)
                {
                    size_t neighbor = static_cast<size_t>(neighbors[i]);
                    if (color[neighbor] == -1)
                    {                                   // If the neighbor has not been visited
                        color[neighbor] = 1 - color[u]; // Assign the opposite color to the neighbor
                        q.push(neighbor);

                        // Add the vertex to the appropriate set
                        if (color[neighbor] == 0)
                        {
                            A.push_back(neighbor);
                        }
                        else
                        {
                            B.push_back(neighbor);
                        }
                    }
                    else if (color[neighbor] == color[u])
                    { // If the neighbor has the same color as the current vertex
                        return "The graph is not bipartite";
                    }
                }
            }

            // Build the output string showing the two sets
            string result = "The graph is bipartite: A={";
            for (size_t i = 0; i < A.size(); ++i)
            {
                result += to_string(A[i]);
                if (i < A.size() - 1)
                {
                    result += ", ";
                }
                else
                {
                    result += "}, B={";
                }
            }
            for (size_t i = 0; i < B.size(); ++i)
            {
                result += to_string(B[i]);
                if (i < B.size() - 1)
                {
                    result += ", ";
                }
            }
            result += "}";

            return result;
        }

        /**
         * @brief Helper method to perform depth-first search (DFS) traversal to detect cycles in a graph.
         *
         * @param g The graph to check for cycles.
         * @param v The current vertex being visited.
         * @param visited Vector to track visited vertices during DFS traversal.
         * @param currentPath Vector to store the current path in the DFS traversal.
         * @param isVisiting Vector to mark vertices currently being visited in the DFS traversal.
         * @param parent The parent vertex of the current vertex in the DFS traversal.
         * @return true if a cycle is detected, false otherwise.
         */
        bool isContainsCycleUtil(Graph &g, size_t v, vector<bool> &visited, vector<int> &currentPath, vector<bool> &isVisiting, int parent)
        {
            visited[v] = true;
            isVisiting[v] = true;
            currentPath.push_back(v);

            // Traverse all neighbors of vertex v
            vector<int> neighbors = g.getNeighbors(v);
            for (size_t i = 0; i < neighbors.size(); ++i)
            {
                size_t neighbor = static_cast<size_t>(neighbors[i]);
                if (!visited[neighbor])
                {
                    // If the neighbor is not visited, recursively call the function
                    if (isContainsCycleUtil(g, neighbor, visited, currentPath, isVisiting, v))
                    {
                        return true;
                    }
                }
                else if (isVisiting[neighbor] && neighbor != parent)
                {
                    // If the neighbor is currently being visited and is not the parent of v, there is a cycle
                    return true;
                }
            }

            // Backtrack: Mark the vertex as not currently being visited
            isVisiting[v] = false;
            // Remove the vertex from the current path
            currentPath.pop_back();

            return false;
        }

        bool isContainsCycle(Graph &g)
        {
            // Vector to keep track of visited vertices
            vector<bool> visited(g.getNumberOfVertices(), false);
            // Vector to keep track of vertices currently being visited in the DFS traversal
            vector<bool> visiting(g.getNumberOfVertices(), false);
            // Vector to store the current path in the DFS traversal
            vector<int> path;

            // Perform DFS traversal from each vertex
            for (size_t i = 0; i < g.getNumberOfVertices(); ++i)
            {
                if (!visited[i] && isContainsCycleUtil(g, i, visited, path, visiting, -1))
                {
                    // If a cycle is found in any DFS traversal, return true
                    return true;
                }
            }

            // No cycle found in any DFS traversal
            return false;
        }

        string negativeCycle(Graph g)
        {
            // Check if the graph has no edges
            if (g.getNumberOfEdges() == 0)
            {
                return "there are no edges in the graph.";
            }
            
            // Check if the graph is empty
            if (g.getNumberOfVertices() == 0)
            {
                return "empty graph!";
            }


            // Check if there are no negative edges in the graph
            if (!g.isNegativeEdge())
            {
                return " no negative edges in the graph";
            }

            // Initialize variables
            int n = g.getNumberOfVertices();
            // Initialize distances from source vertex to all other vertices
            vector<int> distance(static_cast<size_t>(n), INT_MAX);
            distance[0] = 0; // Distance to source vertex is 0

            // Relax edges repeatedly to find shortest paths
            for (int i = 0; i < n - 1; ++i)
            {
                for (size_t u = 0; u < n; ++u)
                {
                    for (size_t v = 0; v < n; ++v)
                    {
                        int weight = g.getEdgeWeight(u, v);
                        // Check if the edge exists and if the distance can be improved
                        if ((weight != 0 || u == v) && distance[u] + weight < distance[v])
                        {
                            distance[v] = distance[u] + weight; // Update the distance
                        }
                    }
                }
            }

            // Check for negative weight cycle
            for (size_t u = 0; u < n; ++u)
            {
                for (size_t v = 0; v < n; ++v)
                {
                    int weight = g.getEdgeWeight(u, v);
                    // Check if the edge exists and if there is a negative cycle
                    if ((weight != 0 || u == v) && distance[u] + weight < distance[v])
                    {
                        return "there is a Negative cycle in the graph.";
                    }
                }
            }

            // If no negative cycle is found
            return "there is No negative cycle in the graph.";
        }

        string shortestPath(Graph g, size_t start, size_t end)
        {
            // Get the number of vertices in the graph
            size_t n = g.getNumberOfVertices();

            // Check for invalid input or trivial cases
            if (start == end || n == 0 || start >= n || end >= n || end < 0)
            {
                return "";
            }

            // If the graph is a weighted graph and contains negative edges
            if (g.isWeightedGraph() && g.isNegativeEdge())
            {
                // Check for negative cycles
                if (negativeCycle(g) == "there is a Negative cycle in the graph.")
                {
                    return "there is a Negative cycle in the graph.";
                }

                // Initialize distance array with maximum values
                vector<int> dist(n, INT_MAX);
                // Set the distance of the start vertex to 0
                dist[start] = 0;

                // Relax edges repeatedly to find shortest paths
                for (size_t i = 0; i < n - 1; i++)
                {
                    for (size_t u = 0; u < n; u++)
                    {
                        vector<int> neighbors = g.getNeighbors(u);
                        for (size_t j = 0; j < neighbors.size(); j++)
                        {
                            int neighbor = neighbors[j];
                            int weight = g.getEdgeWeight(u, (size_t)neighbor);
                            if (dist[u] + weight < dist[(size_t)neighbor])
                            {
                                dist[(size_t)neighbor] = dist[u] + weight;
                            }
                        }
                    }
                }

                // Check for negative cycles
                for (size_t u = 0; u < n; u++)
                {
                    vector<int> neighbors = g.getNeighbors(u);
                    for (size_t j = 0; j < neighbors.size(); j++)
                    {
                        int neighbor = neighbors[j];
                        int weight = g.getEdgeWeight(u, (size_t)neighbor);
                        if (dist[u] + weight < dist[(size_t)neighbor])
                        {
                            return "there is a Negative cycle in the graph.";
                        }
                    }
                }

                // Reconstruct the shortest path
                string path = "";
                queue<int> q;
                size_t current = end;
                while (current != start)
                {
                    q.push(current);
                    vector<int> neighbors = g.getNeighbors(current);
                    for (size_t j = 0; j < neighbors.size(); j++)
                    {
                        int neighbor = neighbors[j];
                        if (dist[(size_t)neighbor] + g.getEdgeWeight(current, (size_t)neighbor) == dist[current])
                        {
                            current = (size_t)neighbor;
                            break;
                        }
                    }
                }
                q.push(start);
                while (!q.empty())
                {
                    path = to_string(q.front()) + "->" + path;
                    q.pop();
                }
                return path;
            }
            // If the graph is a weighted graph
            else if (g.isWeightedGraph())
            {
                // Initialize distance and predecessor arrays
                vector<int> dist(n, INT_MAX);
                vector<int> pred(n, -1);

                // Priority queue to store vertices being processed
                priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

                // Set the distance of the start vertex to 0
                dist[start] = 0;

                // Push the start vertex into the priority queue
                pq.push(make_pair(0, start));

                // Dijkstra's algorithm to find shortest paths
                while (!pq.empty())
                {
                    size_t u = (size_t)pq.top().second;
                    pq.pop();

                    if (dist[u] != pq.top().first)
                        continue;

                    for (size_t v = 0; v < n; ++v)
                    {
                        int weight = g.getEdgeWeight(u, v);
                        if (weight == 0)
                            continue;

                        if (dist[v] > dist[u] + weight)
                        {
                            dist[v] = dist[u] + weight;
                            pq.push(make_pair(dist[v], v));
                            pred[v] = u;
                        }
                    }
                }

                // Reconstruct the shortest path
                if (dist[end] == INT_MAX)
                {
                    return "There is no path from " + to_string(start) + " to " + to_string(end);
                }
                else
                {
                    string path = to_string(end);
                    int current = pred[end];
                    while (current != -1)
                    {
                        path = to_string(current) + "->" + path;
                        if (current == start)
                            break;
                        current = pred[(size_t)current];
                    }
                    return path;
                }
            }
            // If the graph is an unweighted graph (BFS)
            else
            {
                // Initialize distance and predecessor arrays
                vector<int> dist(g.getNumberOfVertices(), INT_MAX);
                vector<int> pred(g.getNumberOfVertices(), -1);

                // Set the distance of the start vertex to 0
                dist[start] = 0;
                queue<int> q;
                q.push(start);

                // BFS to find shortest paths
                while (!q.empty())
                {
                    size_t u = (size_t)q.front();
                    q.pop();
                    vector<int> neighbors = g.getNeighbors(u);
                    for (size_t j = 0; j < neighbors.size(); j++)
                    {
                        int neighbor = neighbors[j];
                        if (dist[(size_t)neighbor] == INT_MAX)
                        {
                            dist[(size_t)neighbor] = dist[u] + 1;
                            q.push((size_t)neighbor);
                            pred[(size_t)neighbor] = u;
                        }
                    }
                }

                // Reconstruct the shortest path
                if (dist[end] == INT_MAX)
                {
                    return "There is no path from " + to_string(start) + " to " + to_string(end);
                }
                else
                {
                    int current = end;
                    string path = to_string(current);
                    current = pred[(size_t)current];
                    while (current != start)
                    {
                        path = to_string(current) + "->" + path;
                        current = pred[(size_t)current];
                    }
                    path = to_string(start) + "->" + path;
                    return path;
                }
            }
        }

    } // namespace Algorithms
} // namespace ariel
