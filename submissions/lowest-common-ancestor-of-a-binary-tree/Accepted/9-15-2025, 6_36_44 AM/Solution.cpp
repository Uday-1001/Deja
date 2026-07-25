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
        //if we get a null node
        if(root == nullptr) return nullptr;
        //if we get a node equal to p
        if(root->val == p->val) return p;
        //if we get a node equal to q
        if(root->val == q->val) return q;

        //traverse via resursion
        TreeNode* left_ans = lowestCommonAncestor(root->left , p , q);
        TreeNode* right_ans = lowestCommonAncestor(root->right , p , q);

        //if both are null it means it is not the req ans
        if(left_ans == nullptr && right_ans == nullptr)
            return nullptr;

        //if one of them is not null means that node can be the LCA
        else if(left_ans != nullptr && right_ans == nullptr)
            return left_ans;
        else if(left_ans == nullptr && right_ans != nullptr)
            return right_ans;

        //if both of them are returned as output to a node means that the node is the req ans
        else
            return root;
    }
};