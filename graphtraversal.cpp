/*


        Problem Statement:
            Graph traversal:The area around the college and the prominent
                            landmarks of it are represented using graphs.
                            Write a menu driven C++ program to represent this as a graph using
                            adjacency matrix /list and perform DFS and BFS.
*/

#include <iostream>
#include <stack>
using namespace std;

class Graph
{
public:
    int vertices;
    int **adjMatrix;

    Graph(int v)
    {
        vertices = v;
        adjMatrix = new int *[vertices];
        for (int i = 0; i < vertices; i++)
        {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int v, int w)
    {
        adjMatrix[v][w] = 1;
        adjMatrix[w][v] = 1;
    }

    void printadjMatrix()
    {
        cout << "The adjacency matrix is :- " << endl;

        cout << "  ";
        for (int i = 0; i < vertices; i++)
        {
            cout << i << " "; // columns
        }
        cout << endl;

        for (int i = 0; i < vertices; i++)
        {
            cout << i << " "; // rows

            for (int j = 0; j < vertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void bfsTraversal(int startingVertex)
    {
        bool *visited = new bool[vertices];
        int *queue = new int[vertices];
        int front = -1, rear = -1;

        for (int i = 0; i < vertices; i++)
        {
            visited[i] = false;
        }

        visited[startingVertex] = true;
        rear++;
        queue[rear] = startingVertex;

        while (front != rear)
        {
            front++;
            int currentVertex = queue[front];
            cout << currentVertex << " ";

            for (int i = 0; i < vertices; i++)
            {
                if (adjMatrix[currentVertex][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    rear++;
                    queue[rear] = i;
                }
            }
        }
    }

    void dfsTraversal(int startingVertex)
    {
        bool *visited = new bool[vertices];
        stack<int> dfsStack;
        for (int i = 0; i < vertices; i++)
        {
            visited[i] = false;
        }

        cout << "The starting vertex is :- " << startingVertex << endl;
        dfsStack.push(startingVertex);

        while (!dfsStack.empty())
        {
            int currentVertex = dfsStack.top();
            dfsStack.pop();

            if (!visited[currentVertex])
            {
                cout << currentVertex << " ";
                visited[currentVertex] = true;
            }

            for (int i = vertices - 1; i >= 0; i--)
            {
                if (adjMatrix[currentVertex][i] == 1 && !visited[i])
                {
                    dfsStack.push(i);
                }
            }
        }
    }
};

int main()
{
    int vertices;
    int edges, v, w;
    int startingVertex;
    int option;
    cout << "Enter the number of vertices :- ";
    cin >> vertices;
    Graph g(vertices);

    cout << "Enter the number of edges :- ";
    cin >> edges;

    do
    {
        cout << "Choose from the below options." << endl;
        cout << "1.Create a graph." << endl;
        cout << "2.Display the adjacency matrix." << endl;
        cout << "3.To perfrom BFS Traversal." << endl;
        cout << "4.To perfrom DFS Traversal." << endl;
        cout << "5.To exit." << endl;

        cout << "Enter the option :- ";
        cin >> option;

        switch (option)
        {
        case 1:

            cout << "Enter the egdes(vertex1 vertex2) :- " << endl;
            for (int i = 0; i < edges; i++)
            {
                cin >> v >> w;
                g.addEdge(v, w);
            }
            cout << endl;
            cout << "***************************************" << endl;
            break;

        case 2:
            g.printadjMatrix();
            break;

        case 3:
            cout << "Enter the starting vertex to traverse the graph :- ";
            cin >> startingVertex;
            cout << endl;
            g.bfsTraversal(startingVertex);
            cout << endl;
            cout << "***************************************" << endl;
            break;

        case 4:
            cout << "Enter the starting vertex to traverse the graph :- ";
            cin >> startingVertex;
            cout << endl;
            cout << "The DFS Traversal is :- ";
            g.dfsTraversal(startingVertex);
            cout << "***************************************" << endl;
            break;

        case 5:
            cout << "Exiting" << endl;
            exit(0);

        default:
            cout << "Invalid option ! Please enter the valid option." << endl;
            break;
        }
    } while (option != 0);
    return 0;
}

/*
SOLUTION:-
Enter the number of vertices :- 5
Enter the number of edges :- 4
Choose from the below options.
1.Create a graph.
2.Display the adjacency matrix.
3.To perfrom BFS Traversal.
4.To perfrom DFS Traversal.
5.To exit.
Enter the option :- 1
Enter the egdes(vertex1 vertex2) :-
0 1
1 2
2 3
3 4

***************************************
Choose from the below options.
1.Create a graph.
2.Display the adjacency matrix.
3.To perfrom BFS Traversal.
4.To perfrom DFS Traversal.
5.To exit.
Enter the option :- 2
The adjacency matrix is :-
  0 1 2 3 4
0 0 1 0 0 0
1 1 0 1 0 0
2 0 1 0 1 0
3 0 0 1 0 1
4 0 0 0 1 0
Choose from the below options.
1.Create a graph.
2.Display the adjacency matrix.
3.To perfrom BFS Traversal.
4.To perfrom DFS Traversal.
5.To exit.
Enter the option :- 3
Enter the starting vertex to traverse the graph :- 1

1 0 2 3 4
***************************************
Choose from the below options.
1.Create a graph.
2.Display the adjacency matrix.
3.To perfrom BFS Traversal.
4.To perfrom DFS Traversal.
5.To exit.
Enter the option :- 4
Enter the starting vertex to traverse the graph :- 0

The DFS Traversal is :- The starting vertex is :- 0
0 1 2 3 4 ***************************************
Choose from the below options.
1.Create a graph.
2.Display the adjacency matrix.
3.To perfrom BFS Traversal.
4.To perfrom DFS Traversal.
5.To exit.
Enter the option :- 5
Exiting
*/