// https://leetcode.com/problems/recover-binary-search-tree

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
    TreeNode*prev = nullptr;
    TreeNode* first_violation = nullptr;
    TreeNode* second_violation = nullptr;
    
    void solve(TreeNode* root)
    {
        if(!root) return;

        solve(root->left);

        if(prev && root->val < prev->val)
        {
            if(first_violation == nullptr) first_violation = prev;
            second_violation = root;
        }
        prev = root;

        solve(root->right);
    }

    void recoverTree(TreeNode* root) {
        solve(root);
        swap(first_violation->val , second_violation->val);
    }
};