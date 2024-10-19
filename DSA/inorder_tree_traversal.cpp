#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int v)
    {
        data = v;
        left = right = NULL;
    }
};

// inorder traversal function
void printInorder(struct Node *node)
{
    if (node == NULL)
        return;
    // left subtree
    printInorder(node->left);
    // print the node data
    cout << node->data << " ";
    // right subtree
    printInorder(node->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    printInorder(root);

    return 0;
}