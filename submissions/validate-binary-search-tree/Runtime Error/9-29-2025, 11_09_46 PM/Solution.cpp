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
    bool valid(TreeNode* root)
    {
        //base case 
        if(!root) return true;
        if(root->left->val < root->val && root->right->val > root->val)
        {
            return true;
        }
        return false;

        //ek case hum solve karenge baaki ka recursion karega 
        bool left_ans = valid(root->left);
        bool right_ans = valid(root->right);

        return left_ans || right_ans;
    }

    bool isValidBST(TreeNode* root) {
        return valid(root);
    }
};