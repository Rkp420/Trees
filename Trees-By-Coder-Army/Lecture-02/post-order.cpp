// https://www.geeksforgeeks.org/problems/postorder-traversal/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions

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
    void solve(Node *curr, vector<int> &post)
    {
        if (!curr)
            return;

        if (curr->left)
            solve(curr->left, post);
        if (curr->right)
            solve(curr->right, post);
        post.push_back(curr->data);
    }
    vector<int> postOrder(Node *root)
    {
        vector<int> post;
        solve(root, post);

        return post;
    }
};

int main()
{
    return 0;
}