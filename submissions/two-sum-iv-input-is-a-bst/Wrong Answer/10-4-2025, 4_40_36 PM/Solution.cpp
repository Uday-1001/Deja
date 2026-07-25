// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    void getinorder(vector<int>&inorder , TreeNode* root)
    {
        if(!root) return;

        getinorder(inorder , root->left);
        inorder.push_back(root->val);
        getinorder(inorder , root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        getinorder(inorder , root);

        int i = 0;
        int j = inorder.size()-1;

        while(i <= j)
        {
            int sum = inorder[i] + inorder[j];

            if(sum == k) return true;
            else
            {
                if(sum < k)
                    i++;
                else 
                    j--;
            }
        }
        return false;
    }
};