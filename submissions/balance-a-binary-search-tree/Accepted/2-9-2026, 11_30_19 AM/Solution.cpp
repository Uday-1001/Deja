// https://leetcode.com/problems/balance-a-binary-search-tree

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
    void inorderfilling(TreeNode* root , vector<int>&inorder)
    {
        if(!root) return;
        inorderfilling(root->left , inorder);
        inorder.push_back(root->val);
        inorderfilling(root->right , inorder);
    }

    TreeNode* makingTree(int s , int e , vector<int>&inorder)
    {
        if(s > e) return nullptr;
        int mid = s+(e-s)/2;
        int node_val = inorder[mid];

        TreeNode* rootnode = new TreeNode(node_val);
        rootnode->left = makingTree(s , mid-1 , inorder);
        rootnode->right = makingTree(mid+1 , e , inorder);

        return rootnode;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        inorderfilling(root , inorder);

        return makingTree(0 , inorder.size()-1 , inorder);
    }
};