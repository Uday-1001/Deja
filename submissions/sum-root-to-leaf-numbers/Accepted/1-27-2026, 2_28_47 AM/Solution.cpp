// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    void solve(TreeNode* root , int sum , int &total)
    {
        if(!root) return;

        sum = (sum * 10) + root->val;

        if(!root->left and !root->right)
        {
            total += sum;
            return;
        } 

        if(root->left)
        {
            solve(root->left , sum , total);
        }
        if(root->right) 
        {
            solve(root->right , sum , total);
        }
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0 , total = 0;
        solve(root , sum , total);
        return total;
    }
};