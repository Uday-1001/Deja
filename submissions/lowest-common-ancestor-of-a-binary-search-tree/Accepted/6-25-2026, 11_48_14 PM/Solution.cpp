// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree

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
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root) return nullptr;
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;

        auto leftans = LCA(root->left , p , q);
        auto rightans = LCA(root->right , p , q);

        if(leftans and rightans) return root;
        else if(leftans and !rightans) return leftans;
        else if(!leftans and rightans) return rightans;
        else return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root , p , q);
    }
};