// https://leetcode.com/problems/kth-smallest-element-in-a-bst

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
    int ans = 0;
    int count;
    void solve(TreeNode* root)
    {
        if(!root) return;
        solve(root->left);
        count--;
        if(count == 0) 
        {
            ans = root->val;
            return;
        }
        solve(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        count = k;
        solve(root);
        return ans;
    }
};