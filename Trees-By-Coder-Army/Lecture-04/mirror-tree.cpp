// https://www.geeksforgeeks.org/problems/mirror-tree/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    void rotate(Node *x)
    {
        if (x->left == NULL && x->right == NULL)
            return;

        Node *temp = x->left;
        x->left = x->right;
        x->right = temp;

        if (x->left)
            rotate(x->left);
        if (x->right)
            rotate(x->right);
    }

    void mirror(Node *root)
    {
        if (root == NULL)
            return;

        rotate(root);
    }
};

class Solution2
{
public:
    void mirror(Node *node)
    {

        if (!node)
            return;

        mirror(node->left);
        mirror(node->right);

        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};

int main()
{
    return 0;
}