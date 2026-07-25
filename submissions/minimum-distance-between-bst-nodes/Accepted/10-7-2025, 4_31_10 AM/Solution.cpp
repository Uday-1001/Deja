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
    void solve(TreeNode* root , int& mini , TreeNode*& prev)
    {
        if(!root) return;

        solve(root->left , mini , prev);
        if(prev) 
        {
            mini = min(mini , root->val - prev->val);
        }
        prev = root;
        solve(root->right , mini , prev);
    }

    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        int mini = INT_MAX;

        solve(root , mini , prev);
        return mini;
    }
};