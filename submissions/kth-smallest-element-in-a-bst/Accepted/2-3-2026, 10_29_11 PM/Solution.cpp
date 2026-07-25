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
    void fillingInorder(TreeNode* root , vector<int>&inorder)
    {
        if(!root) return;
        fillingInorder(root->left , inorder);
        inorder.push_back(root->val);
        fillingInorder(root->right , inorder);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorder;
        fillingInorder(root , inorder);

        return inorder[k-1];
    }
};