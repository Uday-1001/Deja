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
//FASTER WAY TO DO IN O(N)->

    bool curr_Balance = true;

    int getheight(TreeNode* root)
    {
        if(!root) return 0;

        auto left = getheight(root->left);
        auto right = getheight(root->right);

        if(curr_Balance && abs(left - right) > 1) 
            curr_Balance = false;

        return 1 + max(left , right);
    }

    bool isBalanced(TreeNode* root) {
        getheight(root);
        return curr_Balance;
    }
};