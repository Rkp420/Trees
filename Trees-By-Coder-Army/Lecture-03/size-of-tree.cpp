
#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/problems/size-of-binary-tree/1?page=1&difficulty%5B%5D=-1&category%5B%5D=Tree&sortBy=submissions

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
    int getSize(Node *node)
    {

        int ans = 0;

        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            ans++;

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        return ans;
    }
};

int main()
{
    return 0;
}