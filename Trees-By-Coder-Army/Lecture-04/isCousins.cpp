#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    bool isCousins(Node *root, int x, int y)
    {
        if (!root)
            return false;

        Node *parentA;
        Node *parentB;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            parentA = parentB = nullptr;
            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                if (curr->left)
                {
                    if (curr->left->data == x)
                        parentA = curr;
                    if (curr->left->data == y)
                        parentB = curr;
                    q.push(curr->left);
                }

                if (curr->right)
                {
                    if (curr->right->data == x)
                        parentA = curr;
                    if (curr->right->data == y)
                        parentB = curr;
                    q.push(curr->right);
                }
            }

            if (parentA && parentB)
                return parentA != parentB;

            if (parentA || parentB)
                return false;
        }

        return false;
    }
};

// dfs

class Solution
{
public:
    Node *parentA = nullptr;
    Node *parentB = nullptr;
    int depthA = -1, depthB = -1;

    void dfs(Node *root, Node *parent, int depth, int a, int b)
    {
        if (!root)
            return;

        if (root->data == a)
        {
            parentA = parent;
            depthA = depth;
        }

        if (root->data == b)
        {
            parentB = parent;
            depthB = depth;
        }

        dfs(root->left, root, depth + 1, a, b);
        dfs(root->right, root, depth + 1, a, b);
    }

    bool isCousins(Node *root, int x, int y)
    {
        if (root == NULL)
            return false;

        parentA = parentB = nullptr;
        depthA = depthB = -1;

        dfs(root, NULL, 0, x, y);

        if (depthA == -1 || depthB == -1)
            return false;

        return (depthA == depthB) && (parentA != parentB);
    }
};

int main()
{
    return 0;
}