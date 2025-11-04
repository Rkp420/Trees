
// https://www.geeksforgeeks.org/problems/sum-of-binary-tree/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    int sumBT(Node *root)
    {

        int sum = 0;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            sum += curr->data;

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        return sum;
    }
};

int main()
{
    return 0;
}