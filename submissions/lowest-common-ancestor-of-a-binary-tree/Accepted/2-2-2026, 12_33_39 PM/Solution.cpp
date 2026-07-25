// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;

        TreeNode* left = lowestCommonAncestor(root->left , p , q);
        TreeNode* right = lowestCommonAncestor(root->right , p , q);

        if(!left and !right) return nullptr;
        else if(!left and right) return right;
        else if(left and !right) return left;
        else return root;
    }
};