// https://leetcode.com/problems/minimum-distance-between-bst-nodes

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
    void solve(TreeNode* root , vector<int>&inorder)
    {
        if(!root) return;

        solve(root->left , inorder);
        inorder.push_back(root->val);
        solve(root->left , inorder);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>inorder;
        solve(root , inorder);

        return inorder[1] - inorder[0];
    }
};