/*

    Problem Statement:
            A Dictionary using AVL: A Dictionary stores key and value pairs
            Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be
            comparable, Keys must be unique.
            Standard Operations: Insert(key, value), Find(key), Delete(key)
            Write a menu driven C++ program to provide above standard operations
            on dictionaries and provide a facility to display whole data sorted in
            ascending/ Descending order. Also find how many maximum
            comparisons may require for finding any keyword.
            Use Height balanced tree(AVL) and find the complexity for finding a
            keyword
*/

#include <iostream>
using namespace std;

class node
{
public:
    string key;
    string meaning;
    node *left;
    node *right;
};

class AVL
{
    node *root;

public:
    AVL()
    {
        root = NULL;
    }

    void create();
    node *insert(node *cur, node *temp);
    node *balance(node *temp);
    int dif(node *temp);
    int height(node *temp);
    int maximum(int a, int b);

    node *LL(node *par);
    node *RR(node *par);
    node *LR(node *par);
    node *RL(node *par);

    void ascending(node *temp);
    node *delete_n(node *root, string key1);
    void deleten();

    node *extractmin(node *t);
    void descending(node *temp);
    void display();
    int search(node *cur, string key1); // Changed return type to int
    void search_value();
    node *getRoot()
    {
        return root;
    }

    bool findKey(string key1);
};

void AVL::create()
{
    char answer;
    node *temp;
    do
    {
        temp = new node();
        cout << "\n Enter the keyword:";
        cin >> temp->key;

        cout << "\n Enter the meaning:";
        cin >> temp->meaning;
        temp->left = temp->right = NULL;

        root = insert(root, temp);

        cout << "\n Do you want to add another word?(y/n)";
        cin >> answer;
    } while (answer == 'y' || answer == 'Y');
}

node *AVL::insert(node *cur, node *temp)
{
    if (cur == NULL)
    {
        return temp;
    }
    if (temp->key < cur->key)
    {
        cur->left = insert(cur->left, temp);
        cur = balance(cur);
    }
    else if (temp->key > cur->key)
    {
        cur->right = insert(cur->right, temp);
        cur = balance(cur);
    }
    return cur;
}

node *AVL::balance(node *temp)
{
    int bal;
    bal = dif(temp);

    if (bal >= 2)
    {
        if (dif(temp->left) < 0)
            temp = LR(temp);
        else
            temp = LL(temp);
    }
    else if (bal <= -2)
    {
        if (dif(temp->right) < 0)
            temp = RR(temp);
        else
            temp = RL(temp);
    }
    return temp;
}

int AVL::dif(node *temp)
{
    int l, r;
    l = height(temp->left);
    r = height(temp->right);
    return (l - r);
}

int AVL::height(node *temp)
{
    if (temp == NULL)
        return (-1);
    else
        return (maximum(height(temp->left), height(temp->right)) + 1);
}

int AVL::maximum(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

node *AVL::LL(node *par)
{
    node *temp, *temp1;
    temp = par->left;
    temp1 = temp->right;

    temp->right = par;
    par->left = temp1;
    return temp;
}

node *AVL::RR(node *par)
{
    node *temp, *temp1;
    temp = par->right;
    temp1 = temp->left;
    temp->left = par;
    par->right = temp1;
    return temp;
}

node *AVL::LR(node *par)
{
    par->left = RR(par->left);
    return (LL(par));
}

node *AVL::RL(node *par)
{
    par->right = LL(par->right);
    return (RR(par));
}

void AVL::ascending(node *temp)
{
    if (temp != NULL)
    {
        ascending(temp->left);
        cout << "\n\t" << temp->key << " : " << temp->meaning;
        ascending(temp->right);
    }
}

void AVL::descending(node *temp)
{
    if (temp != NULL)
    {
        descending(temp->right);
        cout << "\n\t" << temp->key << " : " << temp->meaning;
        descending(temp->left);
    }
}

void AVL::display()
{
    cout << "\n The keywords in ascending order are : \n";
    ascending(root);
    cout << "\n The keywords in descending order are : \n";
    descending(root);
}

int AVL::search(node *cur, string key1)
{
    int comparisons = 0; // Counter variable
    while (cur)
    {
        comparisons++; // Increment comparison counter
        if (cur->key == key1)
            return comparisons; // Return number of comparisons made
        if (cur->key > key1)
            cur = cur->left;
        else
            cur = cur->right;
    }
    return comparisons; // Return number of comparisons even if key is not found
}

void AVL::search_value()
{
    string key2;
    cout << "\n Enter the keyword you wish to search : ";
    cin >> key2;
    int comparisons = search(root, key2);
    if (comparisons == 0)
        cout << "\n The entered keyword is not present in the AVL tree";
    else
        cout << "\n The entered keyword is present in the AVL tree, found after " << comparisons << " comparisons";
}

node *AVL::delete_n(node *cur, string key1)
{
    if (!cur)
        return cur;
    if (key1 < cur->key)
        cur->left = delete_n(cur->left, key1);
    else if (key1 > cur->key)
        cur->right = delete_n(cur->right, key1);
    else
    {
        node *l = cur->left;
        node *r = cur->right;
        delete cur;
        if (!r)
            return l;
        node *m = r;

        while (m->left)
            m = m->left;
        m->right = extractmin(r);
        m->left = l;
        return balance(m);
    }
    return balance(cur);
}

node *AVL::extractmin(node *t)
{
    if (!t->left)
        return t->right;
    t->left = extractmin(t->left);
    return balance(t);
}

void AVL::deleten()
{
    string key;
    cout << "\n Enter the keyword to be deleted : ";
    cin >> key;
    root = delete_n(root, key);
}

bool AVL::findKey(string key1)
{
    int comparisons = search(root, key1);
    return (comparisons > 0); // If comparisons are greater than 0, key is found
}

int main()
{
    char c;
    int ch;
    AVL a;
    do
    {
        cout << "*********************************";
        cout << "\n 1.Insert a keyword in AVL tree.";
        cout << "\n 2.Display the AVL tree.";
        cout << "\n 3.Search a keyword";
        cout << "\n 4.Delete a keyword.";
        cout << "\n 5.Ascending : ";
        cout << "\n 6.Descending: ";
        cout << "\n 7.Find a keyword.";
        cout << "\n Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            a.create();
            break;
        case 2:
            a.display();
            break;
        case 3:
            a.search_value();
            break;
        case 4:
            a.deleten();
            break;
        case 5:
            a.ascending(a.getRoot());
            break;
        case 6:
            a.descending(a.getRoot());
            break;
        case 7:
        {
            string key;
            cout << "\nEnter the keyword to find: ";
            cin >> key;
            int comparisons = a.search(a.getRoot(), key);
            if (comparisons > 0)
                cout << "\nThe entered keyword is present in the AVL tree, found after " << comparisons << " comparisons";
            else
                cout << "\nThe entered keyword is not present in the AVL tree";
            break;
        }
        default:
            cout << "\n Wrong choice ! ";
        }
        cout << "\n Do you want to continue? (y/n): ";
        cin >> c;
    } while (c == 'y' || c == 'Y');
    return 0;
}

/*
Output:
*********************************
 1.Insert a keyword in AVL tree.
 2.Display the AVL tree.
 3.Search a keyword
 4.Delete a keyword.
 5.Ascending :
 6.Descending:
 7.Find a keyword.
 Enter your choice : 1

 Enter the keyword:apple

 Enter the meaning:fruit

 Do you want to add another word?(y/n)y

 Enter the keyword:sadness

 Enter the meaning:sorrow

 Do you want to add another word?(y/n)y

 Enter the keyword:brittle

 Enter the meaning:weak

 Do you want to add another word?(y/n)n

 Do you want to continue? (y/n): y
*********************************
 1.Insert a keyword in AVL tree.
 2.Display the AVL tree.
 3.Search a keyword
 4.Delete a keyword.
 5.Ascending :
 6.Descending:
 7.Find a keyword.
 Enter your choice : 2

 The keywords in ascending order are :

    apple : fruit
    brittle : weak
    sadness : sorrow
 The keywords in descending order are :

    sadness : sorrow
    brittle : weak
    apple : fruit
 Do you want to continue? (y/n): y
*********************************
 1.Insert a keyword in AVL tree.
 2.Display the AVL tree.
 3.Search a keyword
 4.Delete a keyword.
 5.Ascending :
 6.Descending:
 7.Find a keyword.
 Enter your choice : 3

 Enter the keyword you wish to search : mango

 The entered keyword is not present in the AVL tree
 Do you want to continue? (y/n): y
*********************************
 1.Insert a keyword in AVL tree.
 2.Display the AVL tree.
 3.Search a keyword
 4.Delete a keyword.
 5.Ascending :
 6.Descending:
 7.Find a keyword.
 Enter your choice : 4

 Enter the keyword to be deleted : apple

 Do you want to continue? (y/n): n


=== Code Execution Successful ===

*/