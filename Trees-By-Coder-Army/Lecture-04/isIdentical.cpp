// https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1?page=1&difficulty[]=0&category[]=Tree&sortBy=submissions

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
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    bool isIdentical(Node *r1, Node *r2)
    {
        if (r1 == NULL && r2 == NULL)
            return true;

        if (r1 == NULL || r2 == NULL)
            return false;

        if (r1->data != r2->data)
            return false;

        return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    }
};

int main()
{
    return 0;
}