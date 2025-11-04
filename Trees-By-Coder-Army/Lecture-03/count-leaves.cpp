
// https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

class Solution
{
public:
    int countLeaves(Node *root)
    {

        int count = 0;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (!curr->left && !curr->right)
            {
                count++;
                continue;
            }

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        return count;
    }
};

int main()
{
    return 0;
}