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
    int getheight(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int left_ht = getheight(root->left);
        int right_ht = getheight(root->right);

        return 1 + max(left_ht , right_ht);
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        int left = getheight(root->left);
        int right = getheight(root->right);

        if(abs(left - right) > 1) return false;
        return true;   
    }
};