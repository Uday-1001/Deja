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
    void solve(vector<vector<int>>&ans , vector<int>&temp,  TreeNode* root, int targetSum)
    {
        //base case 
        if(root == nullptr) return;

        if(root->left == NULL && root->right == NULL)
        {
            temp.push_back(root->val);

            int sum = 0;
            for(int i=0 ; i<temp.size(); i++)
            {
                sum += temp[i];
            }
            if(sum == targetSum)
            {
                ans.push_back(temp);
            }
            temp.pop_back();
            return;
        }
        
        temp.push_back(root->val);

        solve(ans , temp , root->left , targetSum);
        solve(ans , temp , root->right , targetSum);
        
        //simply backtrack if we dont find the target sum yet
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;

        solve(ans , temp , root , targetSum);
        return ans;  
    }
};