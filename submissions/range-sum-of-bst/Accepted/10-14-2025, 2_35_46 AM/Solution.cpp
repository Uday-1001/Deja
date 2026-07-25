// https://leetcode.com/problems/range-sum-of-bst

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
    void traversing(TreeNode* root , int low , int high , int &sum)
    {
        if(!root) return;

        if(root->val >= low && root->val <= high)
        {
            sum += root->val;
            traversing(root->left , low , high , sum);
            traversing(root->right , low , high , sum);
        }
        else if(root->val < low)
        {
            traversing(root->right , low , high , sum);
        }
        else
        {
            traversing(root->left , low , high , sum);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        traversing(root , low , high , sum);
        return sum;
    }
};