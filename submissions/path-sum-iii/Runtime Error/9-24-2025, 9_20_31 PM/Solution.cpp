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
    int path = 0;
    //we calculate a single path that starts from the root 
    void single_path(TreeNode* root , int sum)
    {
        if(!root) return;
        if(sum == root->val) path++;

        single_path(root->left , sum - root->val);
        single_path(root->right , sum - root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        //in order to get the whole tree path , we make use of preorder traversal
        if(root)
        {
            single_path(root , targetSum);
            pathSum(root->left , targetSum);
            pathSum(root->right , targetSum);
        }
    return path;
    }
};