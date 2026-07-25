// https://leetcode.com/problems/path-sum-ii

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
    void solve(vector<vector<int>>&ans , vector<int>temp,  TreeNode* root, int targetSum , int sum)
    {
        //base case 
        if(root == nullptr) return;

        sum = sum + root->val;
        temp.push_back(root->val);

        if(root->left == NULL && root->right == NULL)
        {
            if(sum == targetSum)
            {
                ans.push_back(temp);
            } 
            return;
        }
        
        solve(ans , temp , root->left , targetSum , sum);
        solve(ans , temp , root->right , targetSum , sum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;

        solve(ans , temp , root , targetSum , 0);
        return ans;  
    }
};