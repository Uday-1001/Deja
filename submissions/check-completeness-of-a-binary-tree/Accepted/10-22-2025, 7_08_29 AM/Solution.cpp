// https://leetcode.com/problems/check-completeness-of-a-binary-tree

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
    int node_counting(TreeNode* root)
    {
        if(!root) return 0;
        int left = node_counting(root->left);
        int right = node_counting(root->right);

        return 1 + left + right;
    }

    bool iscomplete(TreeNode* root , int i , int n)
    {
        if(!root) return true;
        if(i > n) return false;

        auto left_ans = iscomplete(root->left , 2*i , n);
        auto right_ans = iscomplete(root->right , 2*i+1 , n);

        return left_ans && right_ans;
    }
    
    bool isCompleteTree(TreeNode* root) {
        int n = node_counting(root);
        return iscomplete(root , 1 , n);
    }
};