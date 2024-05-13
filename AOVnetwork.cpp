/*


        Problem Statement:
                Activity on vertex(AOV) network:Sandy is a well organized person.
                                                Every day he makes a list of things which need to be done and
                                                enumerates them from 1 to n. However, some things need to be done
                                                before others. Write a C++ code to find out whether Sandy can solve all
                                                his duties and if so, print the correct order.
*/

#include <iostream>

using namespace std;

class graph
{
    int vertices;
    int adjacentMatrix[100][100]; // Assuming maximum 100 vertices
    int order[100];               // Assuming maximum 100 vertices
    int orderIndex;

public:
    graph(int vertices)
    {
        this->vertices = vertices;

        // Initialize adjacency matrix with zeros
        for (int i = 0; i < vertices; ++i)
            for (int j = 0; j < vertices; ++j)
                adjacentMatrix[i][j] = 0;

        orderIndex = 0; // Initialize orderIndex
    }

    void createEdge(int u, int v)
    {
        adjacentMatrix[u][v] = 1;
    }

    void TopologicalSort()
    {
        // Calculate in-degree for each vertex
        int indegree_count[100] = {0}; // Assuming maximum 100 vertices

        for (int i = 0; i < vertices; ++i)
            for (int j = 0; j < vertices; ++j)
                indegree_count[j] += adjacentMatrix[i][j];

        int visited_node = 0;

        while (visited_node < vertices)
        {
            int u;
            // Find a vertex with indegree 0
            for (u = 0; u < vertices; ++u)
                if (indegree_count[u] == 0)
                    break;

            if (u == vertices)
            {
                cout << "There's a cycle present in the Graph.\nGiven graph is not DAG" << endl;
                return;
            }

            // Remove vertex u and decrease indegree of adjacent vertices
            indegree_count[u] = -1; // Mark as visited

            if (orderIndex < vertices)
            {
                order[orderIndex++] = u;
            }
            else
            {
                cout << "Error: Array index out of bounds." << endl;
                return;
            }

            for (int v = 0; v < vertices; ++v)
                if (adjacentMatrix[u][v])
                    indegree_count[v] -= 1;

            visited_node++;
        }

        // Check if all tasks were scheduled (no cycle detected)
        if (visited_node != vertices)
        {
            cout << "Sandy cannot finish all his duties. There's a cycle present in the graph." << endl;
            return;
        }

        // Sandy can finish all his duties
        cout << "Sandy can successfully finish all his duties." << endl;

        // Print topological order
        for (int i = 0; i < vertices; ++i)
            cout << order[i] << "\t";
    }
};

int main()
{
    int numVertices, numEdges;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    graph G(numVertices);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < numEdges; ++i)
    {
        int u, v;
        cin >> u >> v;
        G.createEdge(u, v);
    }

    G.TopologicalSort();
    return 0;
}

/*Output :
Enter the number of vertices: 3
Enter the number of edges: 3
Enter the edges (u v):
0 1
1 2
2 1
Sandy can successfully finish all his duties.
0	1	2

=== Code Execution Successful ===
*/