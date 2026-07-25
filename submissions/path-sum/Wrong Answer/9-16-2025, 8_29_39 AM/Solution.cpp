// https://leetcode.com/problems/path-sum

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
    bool solve(TreeNode* root, int targetSum , int sum)
    {
        //base case 
        if(root == NULL && targetSum == sum)  return true;
        if(root == nullptr) return false;
    
        //ek case hum solve karenge
        sum = sum + root->val;

        //leaf node checking and sum matching both are checked here after adding the node value
        bool left_case = solve(root->left , targetSum , sum);
        bool right_case = solve(root->right , targetSum , sum);

        return left_case || right_case;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        int sum = 0;
        return solve(root , targetSum , sum);
    }
};