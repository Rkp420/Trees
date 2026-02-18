
// https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1?page=1&difficulty%5B%5D=0&category%5B%5D=Tree&sortBy=submissions

#include <iostream>
using namespace std;

// Simple BruteForce
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    vector<int> findSpiral(Node *root)
    {
        vector<int> ans;
        bool leftToRight = false;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp(size);

            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                int idx = leftToRight ? i : size - 1 - i;
                temp[idx] = curr->data;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            for (int num : temp)
                ans.push_back(num);

            leftToRight = !leftToRight;
        }

        return ans;
    }
};

// Using Two Stack

class Solution
{
public:
    vector<int>
    findSpiral(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        stack<Node *> s1, s2;
        s1.push(root);

        while (!s1.empty() || !s2.empty())
        {
            // Process s1 (R-L)
            while (!s1.empty())
            {
                Node *curr = s1.top();
                s1.pop();

                ans.push_back(curr->data);

                if (curr->right)
                    s2.push(curr->right);
                if (curr->left)
                    s2.push(curr->left);
            }

            // Process s2 (L-R)
            while (!s2.empty())
            {
                Node *curr = s2.top();
                s2.pop();

                ans.push_back(curr->data);

                if (curr->left)
                    s1.push(curr->left);
                if (curr->right)
                    s1.push(curr->right);
            }
        }
        return ans;
    }
};

// Leetcode -- 103 Version

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/1921393604/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<vector<int>> ans;
        bool leftToRight = true;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                int idx = leftToRight ? i : size - 1 - i;
                temp[idx] = curr->val;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }

            ans.push_back(temp);

            leftToRight = !leftToRight;
        }

        return ans;
    }
};

int main()
{
    return 0;
}