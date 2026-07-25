// https://leetcode.com/problems/diameter-of-binary-tree

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
    int max_diameter = 0;

    int getheight(TreeNode* root)
    {
        if(!root) return 0;

        auto left = getheight(root->left);
        auto right = getheight(root->right);

        max_diameter = max(max_diameter , (left + right));

        return 1 + max(left ,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        getheight(root);
        return max_diameter;
    }
};