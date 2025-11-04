// https://www.geeksforgeeks.org/problems/largest-value-in-each-level/1?page=4&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    vector<int> largestValues(Node *root)
    {
        queue<Node *> q;
        q.push(root);

        vector<int> ans;

        while (!q.empty())
        {
            int s = q.size();

            int currMax = INT_MIN;
            for (int i = 0; i < s; i++)
            {
                Node *curr = q.front();
                q.pop();

                currMax = max(currMax, curr->data);

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            ans.push_back(currMax);
        }

        return ans;
    }
};

int main()
{
    return 0;
}