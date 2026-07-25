// https://leetcode.com/problems/validate-binary-search-tree

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
            long long minval;
            long long maxval;
            bool isBST;
    };

    Info solve (TreeNode* root)
    {
        if(!root)
        {
            Info temp;
            temp.minval = LLONG_MAX;
            temp.maxval = LLONG_MIN;
            temp.isBST = true;
            return temp;
        }
        if(!root->left && !root->right)
        {
            Info temp;
            temp.minval = root->val;
            temp.maxval = root->val;
            temp.isBST = true;
            return temp;
        }

        Info left_ans = solve(root->left);
        Info right_ans = solve(root->right);

        Info curr_ans;
        curr_ans.minval = min({left_ans.minval , right_ans.minval , (long long)root->val});
        curr_ans.maxval = max({left_ans.maxval , right_ans.maxval , (long long)root->val});
        curr_ans.isBST = (root->val > left_ans.maxval && right_ans.minval > root->val && left_ans.isBST && right_ans.isBST);

        return curr_ans;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root).isBST;    
    }
};