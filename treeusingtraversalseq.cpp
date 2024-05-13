/*

    Problem Statement:
        Tree using traversal sequence: Write a C++ program to construct the
        binary tree with a given preorder and inorder sequence and Test your tree
        with all traversals
*/

#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
struct TreeNode
{
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    // Constructor
    TreeNode(T data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

// Function to find index of a value in an array
template <typename T>
int findIndex(T arr[], int start, int end, T value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1; // If the element is not found
}

// Function to construct binary tree from its preorder and inorder traversal
template <typename T>
TreeNode<T> *buildTree(T pre[], T in[], int preStart, int preEnd, int inStart, int inEnd)
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return nullptr;
    }

    T rootValue = pre[preStart];
    TreeNode<T> *root = new TreeNode<T>(rootValue);

    int rootIndexInInorder = findIndex(in, inStart, inEnd, rootValue);
    int leftSubtreeSize = rootIndexInInorder - inStart;

    root->left = buildTree(pre, in, preStart + 1, preStart + leftSubtreeSize, inStart, rootIndexInInorder - 1);
    root->right = buildTree(pre, in, preStart + leftSubtreeSize + 1, preEnd, rootIndexInInorder + 1, inEnd);

    return root;
}

// Function to print pre-order of binary tree
template <typename T>
void preorder(TreeNode<T> *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to print in-order of binary tree
template <typename T>
void inorder(TreeNode<T> *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Function to print post-order of binary tree
template <typename T>
void postorder(TreeNode<T> *root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    char pre[n], in[n];
    cout << "Enter the preorder traversal: ";
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    cout << "Enter the inorder traversal: ";
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    TreeNode<char> *root = buildTree(pre, in, 0, n - 1, 0, n - 1);

    cout << "Pre-order traversal: ";
    preorder(root);
    cout << endl;

    cout << "In-order traversal: ";
    inorder(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}

/*Output:
/tmp/JKMVIAwMzh.o
Enter the number of nodes: 5
Enter the preorder traversal: A B D E C
Enter the inorder traversal: D B E A C
Pre-order traversal: A B D E C
In-order traversal: D B E A C
Post-order traversal: D E B C A


=== Code Execution Successful === */