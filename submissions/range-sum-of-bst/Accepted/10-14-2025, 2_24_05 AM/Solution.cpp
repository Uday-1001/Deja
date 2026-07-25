// https://leetcode.com/problems/range-sum-of-bst

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
    //SIMPLE WAY ..
    void getinorder(vector<int>&inorder , TreeNode* root)
    {
        if(!root) return;

        getinorder(inorder , root->left);
        inorder.push_back(root->val);
        getinorder(inorder , root->right);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>inorder;
        getinorder(inorder , root);

        int total = 0;
        for(auto elem : inorder)
        {
            if(elem >= low && elem <= high)
            {
                total += elem;
            }
        }
        return total;
    }
};