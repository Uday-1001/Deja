// https://leetcode.com/problems/find-duplicate-subtrees

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
    vector<TreeNode*>ans;
    unordered_map<string , int>mp;

    string preorder(TreeNode* root)
    {
        //base case 
        if(!root) return "N";
        
        string node_string = to_string(root->val);
        auto left_string = preorder(root->left);
        auto right_string = preorder(root->right);

        string return_string = node_string + "," + left_string + "," + right_string;
        
        if(mp.find(return_string) != mp.end())
        {
            //means string has been found in the map
            if(mp[return_string] == 1)
                ans.push_back(root);
                
            mp[return_string]++;
        }
        else
        {
            //means string has not been found in the map
            mp[return_string] = 1;
        }
    
    return return_string;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorder(root);
        return ans;
    }
};