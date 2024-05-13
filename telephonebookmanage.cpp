/*
        Problem Statement:
                Telephone book management:  Consider the telephone book database of
                                            N clients.  Write a menu driven C++ program to make use of a hash table
                                            implementation to quickly look up a client's telephone number. Use of
                                            two collision handling techniques and compare them using number of
                                            comparisons required to find a set of telephone numbers
*/

#include <iostream>
#include <cstring>

using namespace std;

const int TABLE_SIZE = 10;

class HashEntry
{
private:
    char *key;
    char *value;

public:
    HashEntry(const char *key, const char *value)
    {
        this->key = new char[strlen(key) + 1];
        strcpy(this->key, key);
        this->value = new char[strlen(value) + 1];
        strcpy(this->value, value);
    }

    ~HashEntry()
    {
        delete[] key;
        delete[] value;
    }

    const char *getKey()
    {
        return key;
    }

    const char *getValue()
    {
        return value;
    }
};

class HashMap
{
private:
    HashEntry **table;

public:
    HashMap()
    {
        table = new HashEntry *[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = nullptr;
    }

    ~HashMap()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            if (table[i] != nullptr)
                delete table[i];
        }
        delete[] table;
    }

    int hashFunction(const char *key)
    {
        int hash = 0;
        for (int i = 0; key[i] != '\0'; ++i)
            hash = (31 * hash + key[i]) % TABLE_SIZE;
        return hash;
    }

    void insert(const char *key, const char *value)
    {
        int hash = hashFunction(key);
        while (table[hash] != nullptr && strcmp(table[hash]->getKey(), key) != 0)
            hash = (hash + 1) % TABLE_SIZE; // Linear probing
        if (table[hash] != nullptr)
            delete table[hash];
        table[hash] = new HashEntry(key, value);
    }

    const char *search(const char *key)
    {
        int hash = hashFunction(key);
        int collisions = 0;
        while (table[hash] != nullptr && strcmp(table[hash]->getKey(), key) != 0)
        {
            hash = (hash + 1) % TABLE_SIZE; // Linear probing
            collisions++;
        }
        if (table[hash] == nullptr)
        {
            cout << "Key not found!" << endl;
            return nullptr;
        }
        else
        {
            cout << "Number of collisions: " << collisions << endl;
            return table[hash]->getValue();
        }
    }
};

int main()
{
    HashMap phonebook;
    int choice;
    char name[50], number[20];
    do
    {
        cout << "\n1. Add a contact\n2. Search for a contact\n3. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter number: ";
            cin >> number;
            phonebook.insert(name, number);
            break;
        case 2:
            cout << "Enter name to search: ";
            cin >> name;
            cout << "Number: " << phonebook.search(name) << endl;
            break;
        case 3:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice!";
        }
    } while (choice != 3);
    return 0;
}
/*Output :

1. Add a contact
2. Search for a contact
3. Exit
Enter your choice: 1
Enter name: alice
Enter number: 1234567980

1. Add a contact
2. Search for a contact
3. Exit
Enter your choice: 1
Enter name: prachiti
Enter number: 2563147890

1. Add a contact
2. Search for a contact
3. Exit
Enter your choice: 1
Enter name: vedant
Enter number: 2456317890

1. Add a contact
2. Search for a contact
3. Exit
Enter your choice: 2
Enter name to search: nilakshi
Number: Key not found!

1. Add a contact
2. Search for a contact
3. Exit
Enter your choice: 2
Enter name to search: vedant
Number: 2456317890

1. Add a contact
2. Search for a contact
3. Exit
Enter your choice: 3

=== Code Execution Successfully ===

*/