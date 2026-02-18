// https : // www.geeksforgeeks.org/problems/check-for-balanced-tree/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    bool checkBalanceWithHeight(Node *root, int &maxHeight)
    {
        if (root == NULL)
        {
            return true;
        }

        int leftHeight = 0;
        bool leftCall = checkBalanceWithHeight(root->left, leftHeight);
        if (!leftCall)
            return false;

        int rightHeight = 0;
        bool rightCall = checkBalanceWithHeight(root->right, rightHeight);
        if (!rightCall)
            return false;

        maxHeight = 1 + max(leftHeight, rightHeight);
        return abs(leftHeight - rightHeight) <= 1;
    }

    bool isBalanced(Node *root)
    {
        if (root == NULL)
            return true;

        int maxHeight = 0;
        return checkBalanceWithHeight(root, maxHeight);
    }
};

int main()
{
    return 0;
}