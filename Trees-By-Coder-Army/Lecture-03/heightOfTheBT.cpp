
// https://www.geeksforgeeks.org/problems/height-of-binary-tree/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    int dfs(Node *curr)
    {
        if (!curr->left && !curr->right)
            return 0;

        int left = INT_MIN;
        int right = INT_MIN;

        if (curr->left)
            left = max(left, dfs(curr->left));
        if (curr->right)
            right = max(right, dfs(curr->right));

        return 1 + max(left, right);
    }
    int height(Node *root)
    {
        return dfs(root);
    }
};

int main()
{
    return 0;
}