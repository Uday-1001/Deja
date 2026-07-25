// https://leetcode.com/problems/house-robber-iii

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root)
    {
        if(!root) return 0;

        int include_node = root->val;
        if(root->left != nullptr)
        {
            include_node += solve(root->left->left) + solve(root->left->right);
        }
        if(root->right != nullptr)
        {
            include_node += solve(root->right->left) + solve(root->right->right);
        }

        int exclude_node = 0 + solve(root->left) + solve(root->right);

        return max(include_node , exclude_node);
    }
    int rob(TreeNode* root) {
        return solve(root);
    }
};