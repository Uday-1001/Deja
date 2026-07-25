// https://leetcode.com/problems/count-good-nodes-in-binary-tree

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
    int count = 0;
    int byrec(TreeNode* root , int maxval)
    {
        if(!root) return 0;

        if(root->val >= maxval) count++;

        int newmax = max(root->val , maxval);

        int left = byrec(root->left , newmax);

        newmax = root->val;
        int right = byrec(root->right , newmax);

        return left + right;
    }

    int goodNodes(TreeNode* root) {
        byrec(root , root->val);
        return count;
    }
};