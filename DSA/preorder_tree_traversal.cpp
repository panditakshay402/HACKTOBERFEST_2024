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

// print preorder traversal function
void printPreorder(struct Node *node)
{
    if (node == NULL)
        return;
    // print the node data
    cout << node->data << " ";
    // left subtree
    printPreorder(node->left);
    // right subtree
    printPreorder(node->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    printPreorder(root);

    return 0;
}
