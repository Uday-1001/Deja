// https://leetcode.com/problems/balanced-binary-tree

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
    bool balance = true;
    int solve(TreeNode* root)
    {
        if(!root) return 0;

        int leftht = solve(root->left);
        int rightht = solve(root->right);

        if(abs(leftht - rightht) > 1) balance = false;

        return max(leftht , rightht) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        solve(root);
        return balance;
    }
};