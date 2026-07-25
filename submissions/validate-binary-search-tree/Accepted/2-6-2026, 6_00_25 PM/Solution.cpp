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
    using ll = long long;
    class Info
    {
        public:
            ll minval;
            ll maxval;
            bool isBst;
    };

    Info checkValidity(TreeNode* root)
    {
        if(!root)
        {
            Info temp;
            temp.minval = LLONG_MAX;
            temp.maxval = LLONG_MIN;
            temp.isBst = true;
            return temp;
        }
        if(!root->left and !root->right)
        {
            Info temp;
            temp.minval = root->val;
            temp.maxval = root->val;
            temp.isBst = true;
            return temp;
        }

        Info left = checkValidity(root->left);
        Info right = checkValidity(root->right);

        Info curr;
        curr.minval = min<ll>({left.minval , right.minval , root->val});
        curr.maxval = max<ll>({left.maxval , right.maxval , root->val});
        curr.isBst = (root->val > left.maxval and root->val < right.minval and right.isBst and left.isBst);

        return curr;
    }

    bool isValidBST(TreeNode* root) {
        return checkValidity(root).isBst;
    }
};