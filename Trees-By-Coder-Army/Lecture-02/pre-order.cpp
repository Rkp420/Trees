
// https: // www.geeksforgeeks.org/problems/preorder-traversal/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions

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
    void solve(Node *curr, vector<int> &pre)
    {
        if (!curr)
            return;

        pre.push_back(curr->data);
        if (curr->left)
            solve(curr->left, pre);
        if (curr->right)
            solve(curr->right, pre);
    }

    vector<int> preOrder(Node *root)
    {
        vector<int> pre;
        solve(root, pre);

        return pre;
    }
};

int main()
{
    return 0;
}