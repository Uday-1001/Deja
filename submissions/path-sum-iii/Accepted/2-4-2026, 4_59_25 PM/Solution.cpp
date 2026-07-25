// https://leetcode.com/problems/path-sum-iii

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
    int paths = 0;

    void byrec(TreeNode * root , int targetSum , ll sum)
    {
        if(!root) return;
        sum += root->val;
        if(sum == targetSum) paths++;

        byrec(root->left , targetSum , sum);
        byrec(root->right , targetSum , sum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        byrec(root , targetSum , 0LL);

        pathSum(root->left , targetSum);
        pathSum(root->right , targetSum);

        return paths;
    }
};