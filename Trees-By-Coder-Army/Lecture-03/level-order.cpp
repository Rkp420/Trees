#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/problems/level-order-traversal/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int s = q.size();

            vector<int> temp;
            for (int i = 0; i < s; i++)
            {
                Node *curr = q.front();
                q.pop();
                temp.push_back(curr->data);

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

int main()
{
    return 0;
}