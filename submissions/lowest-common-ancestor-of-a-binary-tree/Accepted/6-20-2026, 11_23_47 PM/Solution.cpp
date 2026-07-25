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
    TreeNode* solve(TreeNode* root , TreeNode* p , TreeNode* q)
    {
        if(!root) return nullptr;
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;

        auto leftnode = solve(root->left , p , q);
        auto rightnode = solve(root->right , p , q);

        if(leftnode and rightnode) return root;
        else if(leftnode and !rightnode) return leftnode;
        else if(!leftnode and rightnode) return rightnode;
        else return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root , p , q);
    }
};