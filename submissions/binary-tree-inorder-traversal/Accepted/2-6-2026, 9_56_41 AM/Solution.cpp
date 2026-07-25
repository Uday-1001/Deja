// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    void InorderTraversal(TreeNode* root , vector<int>&inorder)
    {
        if(!root) return;
        InorderTraversal(root->left , inorder);
        inorder.push_back(root->val);
        InorderTraversal(root->right , inorder);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        InorderTraversal(root , inorder);
        return inorder;
    }
};