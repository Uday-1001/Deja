// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers

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
    int solve(TreeNode* root , int val)
    {
        if(!root) return 0;
        
        val = (2 * val) + (1 * root->val);

        if(!root->left and !root->right) return val;

        int leftans = solve(root->left , val);
        int rightans = solve(root->right , val);

        return leftans + rightans;
    }

    int sumRootToLeaf(TreeNode* root) {
        return solve(root , 0);
    }
};