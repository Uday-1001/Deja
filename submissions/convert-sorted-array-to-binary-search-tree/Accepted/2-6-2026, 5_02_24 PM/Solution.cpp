// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree

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
    TreeNode* makingTree(vector<int>&nums , int st , int end)
    {
        if(st > end) return nullptr;
        int rootidx = (st + end) / 2;

        TreeNode* root = new TreeNode(nums[rootidx]);
        root->left = makingTree(nums , st , rootidx - 1);
        root->right = makingTree(nums , rootidx + 1 , end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makingTree(nums , 0 , nums.size() -1);
    }
};