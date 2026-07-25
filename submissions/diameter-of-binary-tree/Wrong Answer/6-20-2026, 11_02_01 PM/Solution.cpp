// https://leetcode.com/problems/diameter-of-binary-tree

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
class Solution {
public:
    int solve(TreeNode* root) 
    {
        if(!root) return 0;

        int leftht = solve(root->left);
        int rightht = solve(root->right);

        return max(leftht , rightht) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) { 
        return solve(root->left) + solve(root->right);
    }
};