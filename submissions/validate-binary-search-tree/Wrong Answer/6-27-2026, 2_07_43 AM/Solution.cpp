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
    bool ValidationByConstraints(TreeNode* root , int upperlimit , int lowerlimit)
    {
        //base case 
        if(!root) return true;
        if(root->val >= upperlimit or root->val <= lowerlimit) return false;

        auto leftans = ValidationByConstraints(root->left , root->val , lowerlimit);
        auto rightans = ValidationByConstraints(root->right , upperlimit , root->val);

        return leftans and rightans;
    }

    bool isValidBST(TreeNode* root) {
        if(!root->right and !root->left) return true;
        return ValidationByConstraints(root , INT_MAX , INT_MIN);
    }
};