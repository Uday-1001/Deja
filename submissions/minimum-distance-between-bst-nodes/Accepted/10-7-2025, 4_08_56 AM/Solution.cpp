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
        solve(root->right , inorder);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>inorder;
        solve(root , inorder);

        int mini = INT_MAX;
        for(int i=1 ; i<inorder.size(); i++)
        {
            mini = min(mini , inorder[i] - inorder[i-1]);
        }
        return mini;
    }
};