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
    int dp[10001];
    int solve(TreeNode* root , vector<int>&dp)
    {
        if(!root) return 0;
        if(dp[root] != -1) return dp[root];

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

        return dp[root] = max(include_node , exclude_node);
    }
    int rob(TreeNode* root) {
        dp.memset(dp , -1 , sizeof(dp));
        return solve(root , dp);
    }
};