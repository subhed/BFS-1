// Author: Subhed Chavan
// Batch: December 24
// Problem Statement: Binary tree level order traversal
// Approach: DFS
// Time Complexity: O(n)
// Space Complexity: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        // Base Case
        if (root == NULL)
        {
            return result;
        }

        dfs(root, 0);

        return result;
    }

    void dfs(TreeNode *root, int depth)
    {
        // Base Case
        if (root == NULL)
        {
            return;
        }
        // Check if we ever reached the depth, if yes add element to the result
        if (result.size() >= depth + 1)
        {
            result[depth].push_back(root->val);
        }
        // Else, create a new vector for the depth
        else
        {
            result.push_back({root->val});
        }

        // Run DFS on child nodes
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);

        return;
    }
};