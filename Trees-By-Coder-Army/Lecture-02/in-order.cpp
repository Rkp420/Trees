// https://www.geeksforgeeks.org/problems/inorder-traversal/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions

#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void solve(Node *curr, vector<int> &in)
    {
        if (!curr)
            return;

        if (curr->left)
            solve(curr->left, in);
        in.push_back(curr->data);
        if (curr->right)
            solve(curr->right, in);
    }

    vector<int> inOrder(Node *root)
    {
        vector<int> in;
        solve(root, in);

        return in;
    }
};

int main()
{
    return 0;
}