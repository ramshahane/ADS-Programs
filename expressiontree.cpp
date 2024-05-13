/*

        Problem Statement:
                Expression tree: Write a menu driven C++ program to construct an
                                expression tree from the given prefix expression eg. +--a*bc/def and
                                perform following operations:
                                1. Traverse it using post order traversal (non recursive)
                                2. Delete the entire tree
                                3. Change a tree so that the roles of the left and right pointers are
                                swapped at every node.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

class Prefix
{
public:
    Node *root;

    Prefix()
    {
        root = NULL;
    }

    void create(const string &s);
    void postorderTraversal();
    void deleteTree(Node *node);
    void swapNodes(Node *node);
};

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

Node *createNode(char data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *constructExpressionTree(const string &prefixExpr)
{
    stack<Node *> stk;

    for (int i = prefixExpr.size() - 1; i >= 0; i--)
    {
        if (isOperator(prefixExpr[i]))
        {
            Node *newNode = createNode(prefixExpr[i]);
            newNode->left = stk.top();
            stk.pop();
            newNode->right = stk.top();
            stk.pop();
            stk.push(newNode);
        }
        else if (isalpha(prefixExpr[i]))
        {
            stk.push(createNode(prefixExpr[i]));
        }
    }

    return stk.top();
}

void Prefix::create(const string &s)
{
    root = constructExpressionTree(s);
}

void Prefix::postorderTraversal()
{
    if (root == NULL)
        return;
    stack<Node *> stk1, stk2;
    stk1.push(root);

    while (!stk1.empty())
    {
        Node *temp = stk1.top();
        stk1.pop();
        stk2.push(temp);

        if (temp->left)
            stk1.push(temp->left);
        if (temp->right)
            stk1.push(temp->right);
    }

    while (!stk2.empty())
    {
        cout << stk2.top()->data << " ";
        stk2.pop();
    }
    cout << endl;
}

void Prefix::deleteTree(Node *node)
{
    if (node == NULL)
        return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void Prefix::swapNodes(Node *node)
{
    if (node == NULL)
        return;

    swap(node->left, node->right);
    swapNodes(node->left);
    swapNodes(node->right);
}

int main()
{
    Prefix exp;
    int ch;
    string s;
    do
    {
        cout << "-------------------MENU--------------------" << endl;
        cout << "1. Create tree" << endl;
        cout << "2. Post order traversal" << endl;
        cout << "3. Delete node" << endl;
        cout << "4. Swap lseft and right nodes." << endl;

        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the Prefix Expression : ";
            cin >> s;
            exp.create(s);
            break;

        case 2:
            cout << "Postorder Traversal: ";
            exp.postorderTraversal();
            break;

        case 3:
            exp.deleteTree(exp.root);
            exp.root = NULL;
            cout << "Tree deleted." << endl;
            break;

        case 4:
            exp.swapNodes(exp.root);
            cout << "Left and right nodes swapped." << endl;
            break;

        case 5:
            cout << "Exiting the program !" << endl;
            break;

        default:
            cout << "Invalid input ! " << endl;
            break;
        }
    } while (ch != 5);
    return 0;
}

/*

OUTPUT:-
-------------------MENU--------------------
1. Create tree
2. Post order traversal
3. Delete node
4. Swap lseft and right nodes.
Enter your choice : 1
Enter the Prefix Expression :  +--a*bc/def
-------------------MENU--------------------
1. Create tree
2. Post order traversal
3. Delete node
4. Swap lseft and right nodes.
Enter your choice : 2
Postorder Traversal: a b c * - d e / - f +
-------------------MENU--------------------
1. Create tree
2. Post order traversal
3. Delete node
4. Swap lseft and right nodes.
Enter your choice : 4
Left and right nodes swapped.
-------------------MENU--------------------
1. Create tree
2. Post order traversal
3. Delete node
4. Swap lseft and right nodes.
Enter your choice : 2
Postorder Traversal: f e d / c b * a - - +
-------------------MENU--------------------
1. Create tree
2. Post order traversal
3. Delete node
4. Swap lseft and right nodes.
Enter your choice : 3
Tree deleted.
-------------------MENU--------------------
1. Create tree
2. Post order traversal
3. Delete node
4. Swap lseft and right nodes.
Enter your choice : 5
Exiting the program !
PS C:\Users\vedan\OneDrive\Desktop\Advance Data Structures Practicals>
*/