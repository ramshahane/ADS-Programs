/*


        Problem Statement:
            Flight management:There are flight paths between cities. If there is a
                            flight between city A and city B then there is an edge between the cities.
                            The cost of the edge can be the time that flight takes to reach city B from
                            A, or the amount of fuel used for the journey.
                            Write a menu driven C++ program to represent this as a graph using
                            adjacency matrix and adjacency list. The node can be represented by the
                            airport name or name of the city. Check whether cities are connected
                            through flight or not. Compare the storage representation. */

#include <iostream>
#include <string>
using namespace std;

class flight
{
public:
    int am[10][10];
    string city_index[10];
    flight();
    int create();
    void displayAdjMatrix(int city_count);
    void displayAdjList(int city_count);
};

flight::flight()
{
    for (int i = 0; i < 10; i++)
    {
        city_index[i] = "--";
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            am[i][j] = 0;
        }
    }
}

int flight::create()
{
    int city_count = 0, wt;
    char c;

    cout << "\n\tEnter the number of cities: ";
    int num_cities;
    cin >> num_cities;

    for (int i = 0; i < num_cities; ++i)
    {
        cout << "\n\tEnter City " << i + 1 << ": ";
        cin >> city_index[i];
        city_count++;
    }

    for (int i = 0; i < num_cities; ++i)
    {
        for (int j = 0; j < num_cities; ++j)
        {
            if (i != j)
            {

                cout << "\n\tIs there an edge from " << city_index[i] << " to " << city_index[j] << " ? (y/n): ";
                char choice;
                cin >> choice;

                if (choice == 'y' || choice == 'Y')
                {
                    cout << "\n\tEnter the distance (weight) of the edge: ";
                    cin >> wt;
                    am[i][j] = wt;
                }
            }
        }
    }

    return city_count;
}

void flight::displayAdjMatrix(int city_count)
{
    int i, j;
    bool incoming_edge, outgoing_edge;

    cout << "\n\t Displaying Adjacency Matrix :\n\t";

    // Check if any cities were added
    if (city_count == 0)
    {
        cout << "\n\t No cities added.\n";
        return;
    }

    // Print header with only used city names
    for (i = 0; i < city_count; i++)
        cout << "\t" << city_index[i];
    cout << "\n";

    // Print matrix
    for (i = 0; i < city_count; i++)
    {
        incoming_edge = false;
        outgoing_edge = false;

        cout << "\t" << city_index[i];
        for (j = 0; j < city_count; j++)
        {
            cout << "\t" << am[i][j];

            // Check if there is an incoming edge
            if (am[j][i] != 0)
            {
                incoming_edge = true;
            }

            // Check if there is an outgoing edge
            if (am[i][j] != 0)
            {
                outgoing_edge = true;
            }
        }

        // Print a message if the city is isolated
        if (incoming_edge == false && outgoing_edge == false)
        {
            cout << "\t(This city is isolated)";
        }

        cout << "\n";
    }
}

void flight::displayAdjList(int city_count)
{
    cout << "\n\t Displaying Adjacency List :\n";

    // Check if any cities were added
    if (city_count == 0)
    {
        cout << "\n\t No cities added.\n";
        return;
    }

    for (int i = 0; i < city_count; i++)
    {
        bool has_incoming_edges = false;
        bool has_outgoing_edges = false;

        // Check for incoming edges
        for (int j = 0; j < city_count; j++)
        {
            if (am[j][i] != 0)
            {
                has_incoming_edges = true;
                break;
            }
        }

        // Check for outgoing edges
        for (int j = 0; j < city_count; j++)
        {
            if (am[i][j] != 0)
            {
                has_outgoing_edges = true;
                break;
            }
        }

        // Print a message if the city is isolated
        if (has_incoming_edges == false && has_outgoing_edges == false)
        {
            cout << "\n\t" << city_index[i] << " -> (This city is isolated)";
        }
        else
        {

            cout << "\n\t" << city_index[i] << " -> ";
            for (int j = 0; j < city_count; j++)
            {
                if (am[i][j] != 0)
                {
                    cout << city_index[j] << " ";
                }
            }
        }
    }

    cout << "\n";
}

int main()
{
    flight f;
    int n, city_count;
    char c;
    do
    {
        cout << "\n\t*** Flight Main Menu *****";
        cout << "\n\t1. Create \n\t2. Adjacency Matrix\n\t3. Adjacency List\n\t4. Exit";
        cout << "\n\t.....Enter your choice : ";
        cin >> n;

        switch (n)
        {
        case 1:
            city_count = f.create();
            break;
        case 2:
            f.displayAdjMatrix(city_count);
            break;
        case 3:
            f.displayAdjList(city_count);
            break;
        case 4:
            return 0;
        }
        cout << "\n\t Do you Want to Continue in Main Menu....(y/n) : ";
        cin >> c;
    } while (c == 'y' || c == 'Y');
    return 0;
}

/* Output :
/tmp/bPnZHCHQLB.o

    *** Flight Main Menu *****
    1. Create
    2. Adjacency Matrix
    3. Adjacency List
    4. Exit
    .....Enter your choice : 1

    Enter the number of cities: 3

    Enter City 1: a

    Enter City 2: b

    Enter City 3: c

    Is there an edge from a to b ? (y/n): y

    Enter the distance (weight) of the edge: 12

    Is there an edge from a to c ? (y/n): n

    Is there an edge from b to a ? (y/n): y

    Enter the distance (weight) of the edge: 13

    Is there an edge from b to c ? (y/n): n

    Is there an edge from c to a ? (y/n): n

    Is there an edge from c to b ? (y/n): n

     Do you Want to Continue in Main Menu....(y/n) : y

    *** Flight Main Menu *****
    1. Create
    2. Adjacency Matrix
    3. Adjacency List
    4. Exit
    .....Enter your choice : 2

     Displaying Adjacency Matrix :
        a	b	c
    a	0	12	0
    b	13	0	0
    c	0	0	0	(This city is isolated)

     Do you Want to Continue in Main Menu....(y/n) : y

    *** Flight Main Menu *****
    1. Create
    2. Adjacency Matrix
    3. Adjacency List
    4. Exit
    .....Enter your choice : 3

     Displaying Adjacency List :

    a -> b
    b -> a
    c -> (This city is isolated)

     Do you Want to Continue in Main Menu....(y/n) : n


=== Code Execution Successful === */