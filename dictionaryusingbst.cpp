/*

        Problem Statement:
        A Dictionary using BST: A Dictionary stores key and value pairs
                            Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be
                            comparable, Keys must be unique.
                            Standard Operations: Insert(key, value), Find(key), Delete(key)
                            Write a menu driven C++ program to provide above standard operations
                            on dictionaries and provide a facility to display whole data sorted in
                            ascending/ Descending order. Also find how many maximum
                            comparisons may require for finding any keyword.
                            Use Binary Search Tree for implementation
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *left;
    Node *right;

    Node(int k, int v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

class Dictionary
{
private:
    Node *root;

    Node *insert(Node *root, int key, int value)
    {
        if (root == nullptr)
        {
            return new Node(key, value);
        }

        if (key < root->key)
        {
            root->left = insert(root->left, key, value);
        }
        else if (key > root->key)
        {
            root->right = insert(root->right, key, value);
        }
        else
        {

            root->value = value;
        }
        return root;
    }

    Node *find(Node *root, int key)
    {
        if (root == nullptr || root->key == key)
        {
            return root;
        }

        if (key < root->key)
        {
            return find(root->left, key);
        }
        else
        {
            return find(root->right, key);
        }
    }

    Node *findMin(Node *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }

    Node *deleteNode(Node *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (key < root->key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {

            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            Node *temp = findMin(root->right);
            root->key = temp->key;
            root->value = temp->value;

            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    void displayInOrder(Node *root)
    {
        if (root != nullptr)
        {
            displayInOrder(root->left);
            cout << "(" << root->key << ", " << root->value << ") ";
            displayInOrder(root->right);
        }
    }

public:
    Dictionary() : root(nullptr) {}

    void insert(int key, int value)
    {
        root = insert(root, key, value);
    }

    Node *find(int key)
    {
        return find(root, key);
    }

    void remove(int key)
    {
        root = deleteNode(root, key);
    }

    void displaySortedAscending()
    {
        displayInOrder(root);
    }

    void displayReverseSorted(Node *root)
    {
        if (root != nullptr)
        {
            displayReverseSorted(root->right);
            cout << "(" << root->key << ", " << root->value << ") ";
            displayReverseSorted(root->left);
        }
    }

    void displaySortedDescending()
    {
        displayReverseSorted(root);
    }

    int getMaxComparisons()
    {
        return getHeight(root);
    }

    int getHeight(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
};

int main()
{
    Dictionary dictionary;
    int choice, key, value;

    do
    {
        cout << "Please Select the following operations to perform :- " << endl;
        cout << "1. Insert" << endl;
        cout << "2. Find" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Display Sorted (Ascending)" << endl;
        cout << "5. Display Sorted (Descending)" << endl;
        cout << "6. Get Maximum Comparisons" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key and value to insert: ";
            cin >> key >> value;
            dictionary.insert(key, value);
            break;
        case 2:
            cout << "Enter key to find: ";
            cin >> key;
            if (dictionary.find(key) != nullptr)
            {
                cout << "Key found\n";
            }
            else
            {
                cout << "Key not found\n";
            }
            break;
        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            dictionary.remove(key);
            cout << "Key deleted\n";
            break;
        case 4:
            cout << "Dictionary in sorted order (ascending): ";
            dictionary.displaySortedAscending();
            cout << endl;
            break;
        case 5:
            cout << "Dictionary in sorted order (descending): ";
            dictionary.displaySortedDescending();
            cout << endl;
            break;
        case 6:
            cout << "Maximum comparisons required: " << dictionary.getMaxComparisons() << endl;
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
            break;
        }
    } while (choice != 7);

    return 0;
}

/* Output :
/tmp/tE7lRnBXN4.o
Please Select the following operations to perform :-
1. Insert
2. Find
3. Delete
4. Display Sorted (Ascending)
5. Display Sorted (Descending)
6. Get Maximum Comparisons
7. Exit
Enter your choice:
1
Enter key and value to insert: 1 9
Please Select the following operations to perform :-
1. Insert
2. Find
3. Delete
4. Display Sorted (Ascending)
5. Display Sorted (Descending)
6. Get Maximum Comparisons
7. Exit
Enter your choice:
1
Enter key and value to insert: 3
2
Please Select the following operations to perform :-
1. Insert
2. Find
3. Delete
4. Display Sorted (Ascending)
5. Display Sorted (Descending)
6. Get Maximum Comparisons
7. Exit
Enter your choice:
1
Enter key and value to insert: 2 5
Please Select the following operations to perform :-
1. Insert
2. Find
3. Delete
4. Display Sorted (Ascending)
5. Display Sorted (Descending)
6. Get Maximum Comparisons
7. Exit
Enter your choice:
2
Enter key to find: 1
Key found
Please Select the following operations to perform :-
1. Insert
2. Find
3. Delete
4. Display Sorted (Ascending)
5. Display Sorted (Descending)
6. Get Maximum Comparisons
7. Exit
Enter your choice:
3
Enter key to delete:  33
Key deleted
Please Select the following operations to perform :-
1. Insert
2. Find
3. Delete
4. Display Sorted (Ascending)
5. Display Sorted (Descending)
6. Get Maximum Comparisons
7. Exit
Enter your choice:
4
Dictionary in sorted order (ascending): (1, 9) (2, 5)
Please Select the following operations to perform :-
1. Insert
2. Find
3. Delete
4. Display Sorted (Ascending)
5. Display Sorted (Descending)
6. Get Maximum Comparisons
7. Exit
Enter your choice:
2
Enter key to find: 3
Key not found
Please Select the following operations to perform :-
1. Insert
2. Find
3. Delete
4. Display Sorted (Ascending)
5. Display Sorted (Descending)
6. Get Maximum Comparisons
7. Exit
Enter your choice:
5
Dictionary in sorted order (descending): (2, 5) (1, 9)
Please Select the following operations to perform :-
1. Insert
2. Find
3. Delete
4. Display Sorted (Ascending)
5. Display Sorted (Descending)
6. Get Maximum Comparisons
7. Exit
Enter your choice:
6
Maximum comparisons required: 2
Please Select the following operations to perform :-
1. Insert
2. Find
3. Delete
4. Display Sorted (Ascending)
5. Display Sorted (Descending)
6. Get Maximum Comparisons
7. Exit
Enter your choice:
7
Exiting...


=== Code Execution Successful ===*/