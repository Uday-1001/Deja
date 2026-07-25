// https://leetcode.com/problems/validate-binary-search-tree

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
    void fillinorder(TreeNode* root , vector<int>&inorder)
    {
        if(!root) return;
        fillinorder(root->left , inorder);
        inorder.push_back(root->val);
        fillinorder(root->right , inorder);
    }

    bool isSorted(vector<int>&inorder)
    {
        int n = inorder.size();
        for(int i = 1 ; i<n ; i++)
        {
            if(inorder[i] <= inorder[i-1]) return false;
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        vector<int>inorder;
        fillinorder(root , inorder);

        return isSorted(inorder);
    }
};