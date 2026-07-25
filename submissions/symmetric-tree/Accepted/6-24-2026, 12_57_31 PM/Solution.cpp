// https://leetcode.com/problems/symmetric-tree

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
    bool isMirror(TreeNode* leftnode , TreeNode* rightnode)
    {
        if(!leftnode and !rightnode) return true;
        if(!leftnode or !rightnode) return false;

        bool leftchild = isMirror(leftnode->left , rightnode->right);
        bool rightchild = isMirror(leftnode->right , rightnode->left);

        return leftnode->val == rightnode->val and leftchild and rightchild;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isMirror(root->left , root->right);
    }
};