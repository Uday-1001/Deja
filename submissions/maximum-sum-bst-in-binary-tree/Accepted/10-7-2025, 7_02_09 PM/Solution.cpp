// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree

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
    class Info
    {
        public:
        int minval;
        int maxval;
        int sum;
        bool isBST;
    };

    Info solve(TreeNode* root , int &sum)
    {
        //base case 
        if(!root)
        {
            Info temp;
            temp.minval = INT_MAX;
            temp.maxval = INT_MIN;
            temp.sum = 0;
            temp.isBST = true;
            sum = max(sum , temp.sum);
            return temp;
        }

        if(!root->left && !root->right)
        {
            Info temp;
            temp.minval = root->val;
            temp.maxval = root->val;
            temp.sum = root->val;
            temp.isBST = true;
            sum = max(sum , temp.sum);
            return temp;
        }

        Info left_ans = solve(root->left , sum);
        Info right_ans = solve(root->right , sum);

        Info curr_ans;
        curr_ans.minval = min({left_ans.minval , right_ans.minval , root->val});
        curr_ans.maxval = max({left_ans.maxval , right_ans.maxval , root->val});
        curr_ans.sum = left_ans.sum + right_ans.sum + root->val;
        curr_ans.isBST = (root->val > left_ans.maxval && root->val < right_ans.minval && left_ans.isBST && right_ans.isBST);

        if(curr_ans.isBST)
        {
            sum = max(sum , curr_ans.sum);
        }
        return curr_ans;
    }

    int maxSumBST(TreeNode* root) {
        int sum = 0;
        solve(root , sum);
        return sum;
    }
};