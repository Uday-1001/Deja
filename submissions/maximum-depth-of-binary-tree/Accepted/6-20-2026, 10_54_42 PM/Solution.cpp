// https://leetcode.com/problems/maximum-depth-of-binary-tree

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

        int leftht = solve(root->left);
        int rightht = solve(root->right);

        return max(leftht , rightht) + 1;
    }

    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        int leftdepth = solve(root->left);
        int rightdepth = solve(root->right);

        return max(leftdepth , rightdepth) + 1;
    }
};