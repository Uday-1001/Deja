// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers

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
    int binaryconversion(string s)
    {
        int power = s.size()-1;
        int binary = 0;
        for(int i = 0 ; i<s.size() ; i++)
        {
            if(s[i] == '1') 
            {
                binary += pow(2 , power);
            }
            power--;
        }
    return binary;
    }

    void solve(TreeNode* root , string path , int &total)
    {
        if(!root) return;
        
        path.push_back(root->val + '0');
        if(!root->left and !root->right)
        {
            int sum = binaryconversion(path);
            total += sum;
            return;
        }

        if(root->left) solve(root->left , path , total);
        if(root->right) solve(root->right , path , total);
    }

    int sumRootToLeaf(TreeNode* root) {
        int total = 0;
        string path = "";

        solve(root , path , total);
        return total;
    }
};