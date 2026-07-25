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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base cases 
        if(!root) return nullptr;
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;

        //we will find out the nodes via recursion
        TreeNode* left = lowestCommonAncestor(root->left , p , q);
        TreeNode* right = lowestCommonAncestor(root->right , p , q);

        if(!left && !right) 
            return NULL;
        else if(left && !right) 
            return left;
        else if(!left && right) 
            return right;
        else  
            return root; 
    }
};