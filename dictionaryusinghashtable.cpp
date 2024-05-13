/*

        Problem Statement:
                A Dictionary using Hash table:
                        A Dictionary stores key and value pairs
                        Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be
                        comparable, Keys must be unique.
                        Standard Operations: Insert(key, value), Find(key), Delete(key)
                        Write a menu driven C++ program to provide above standard operations
                        on dictionaries
                        Write a menu driven C++ program to provide all the functions of a
                        dictionary (ADT) using hashing and handle collisions using chaining.
*/

#include <iostream>
#include <vector>

using namespace std;

// Structure to hold key-value pairs
struct KeyValuePair
{
    int key;
    string value;
    KeyValuePair *next; // Pointer to the next KeyValuePair in case of collisions
};

// Hash table implementation with chaining
class Dictionary
{
private:
    static const int SIZE = 10; // Size of the hash table
    vector<KeyValuePair *> table;

    // Hash function to calculate the index
    int hashFunction(int key)
    {
        return key % SIZE;
    }

public:
    // Constructor to initialize the hash table
    Dictionary()
    {
        table.resize(SIZE, nullptr);
    }

    // Insert a key-value pair into the dictionary
    void insert(int key, const string &value)
    {
        int index = hashFunction(key);
        KeyValuePair *newPair = new KeyValuePair;
        newPair->key = key;
        newPair->value = value;
        newPair->next = nullptr;

        if (table[index] == nullptr)
        {
            table[index] = newPair;
        }
        else
        {
            // Handling collision by chaining
            KeyValuePair *temp = table[index];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newPair;
        }
        cout << "Key-value pair inserted.\n";
    }

    // Find the value associated with a given key
    string find(int key)
    {
        int index = hashFunction(key);
        KeyValuePair *temp = table[index];
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return temp->value;
            }
            temp = temp->next;
        }
        return "Key not found.";
    }

    // Remove a key-value pair from the dictionary
    void remove(int key)
    {
        int index = hashFunction(key);
        if (table[index] == nullptr)
        {
            cout << "Key not found. Cannot remove.\n";
            return;
        }

        if (table[index]->key == key)
        {
            KeyValuePair *temp = table[index];
            table[index] = table[index]->next;
            delete temp;
            cout << "Key-value pair removed.\n";
            return;
        }

        KeyValuePair *prev = table[index];
        KeyValuePair *curr = table[index]->next;
        while (curr != nullptr)
        {
            if (curr->key == key)
            {
                prev->next = curr->next;
                delete curr;
                cout << "Key-value pair removed.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Key not found. Cannot remove.\n";
    }
};

int main()
{
    Dictionary dictionary;
    int choice, key;
    string value;

    do
    {
        cout << "\n1. Insert key-value pair\n";
        cout << "2. Find value by key\n";
        cout << "3. Remove key-value pair\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            dictionary.insert(key, value);
            break;
        case 2:
            cout << "Enter key to find: ";
            cin >> key;
            cout << "Value: " << dictionary.find(key) << endl;
            break;
        case 3:
            cout << "Enter key to remove: ";
            cin >> key;
            dictionary.remove(key);
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

/*
OUTPUT:-

1. Insert key-value pair
2. Find value by key
3. Remove key-value pair
4. Exit
Enter your choice: 1
Enter key: 123
Enter value: John
Key-value pair inserted.

1. Insert key-value pair
2. Find value by key
3. Remove key-value pair
4. Exit
Enter your choice: 1
Enter key: 456
Enter value: Alice
Key-value pair inserted.

1. Insert key-value pair
2. Find value by key
3. Remove key-value pair
4. Exit
Enter your choice: 1
Enter key: 789
Enter value: Bob
Key-value pair inserted.

1. Insert key-value pair
2. Find value by key
3. Remove key-value pair
4. Exit
Enter your choice: 2
Enter key to find: 456
Value: Alice

1. Insert key-value pair
2. Find value by key
3. Remove key-value pair
4. Exit
Enter your choice: 3
Enter key to remove: 123
Key-value pair removed.

1. Insert key-value pair
2. Find value by key
3. Remove key-value pair
4. Exit
Enter your choice: 2
Enter key to find: 123
Value: Key not found.

1. Insert key-value pair
2. Find value by key
3. Remove key-value pair
4. Exit
Enter your choice: 4
Exiting program.

*/