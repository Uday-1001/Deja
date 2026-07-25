// https://leetcode.com/problems/binary-tree-preorder-traversal

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
    //RECURSIVE APPROACH
    vector<int>pre;

    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return pre;

        pre.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return pre;
    }
};