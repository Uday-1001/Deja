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
        if(root == nullptr) return nullptr;
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;

        TreeNode* left_ans = lowestCommonAncestor(root->left , p , q);
        TreeNode* right_ans = lowestCommonAncestor(root->right , p , q);

        if(left_ans == nullptr && right_ans == nullptr)
            return nullptr;
        else if(left_ans != nullptr && right_ans == nullptr)
            return root->left;
        else if(left_ans == nullptr && right_ans != nullptr)
            return root->right;
        else
            return root;
    }
};