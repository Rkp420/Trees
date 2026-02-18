#include <iostream>
using namespace std;

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
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        if (root == NULL)
            return root;

        queue<TreeNode *> q;
        q.push(root);
        int levelSum = root->val;

        while (!q.empty())
        {
            int n = q.size();
            int nextLevelSum = 0;

            while (n--)
            {
                TreeNode *curr = q.front();
                q.pop();

                curr->val = levelSum - curr->val;

                int siblingSum = curr->left != NULL ? curr->left->val : 0;
                siblingSum += curr->right != NULL ? curr->right->val : 0;

                if (curr->left)
                {
                    nextLevelSum += curr->left->val;
                    curr->left->val = siblingSum;
                    q.push(curr->left);
                }

                if (curr->right)
                {
                    nextLevelSum += curr->right->val;
                    curr->right->val = siblingSum;
                    q.push(curr->right);
                }
            }
            levelSum = nextLevelSum;
        }

        return root;
    }
};

class Solution1
{
public:
    vector<long long> levelSum;

    void dfsLevelSum(TreeNode *root, int depth)
    {
        if (root == NULL)
            return;

        if (levelSum.size() == depth)
        {
            levelSum.push_back(0);
        }

        levelSum[depth] += root->val;

        dfsLevelSum(root->left, depth + 1);
        dfsLevelSum(root->right, depth + 1);
    }

    void dfsReplace(TreeNode *root, int depth)
    {
        if (!root)
            return;

        long long childSum = 0;
        if (root->left)
            childSum += root->left->val;
        if (root->right)
            childSum += root->right->val;

        if (root->left)
            root->left->val = levelSum[depth + 1] - childSum;
        if (root->right)
            root->right->val = levelSum[depth + 1] - childSum;

        dfsReplace(root->left, depth + 1);
        dfsReplace(root->right, depth + 1);
    }

    TreeNode *replaceValueInTree(TreeNode *root)
    {
        dfsLevelSum(root, 0);
        root->val = 0;
        dfsReplace(root, 0);
        return root;
    }
};

int main()
{
    return 0;
}