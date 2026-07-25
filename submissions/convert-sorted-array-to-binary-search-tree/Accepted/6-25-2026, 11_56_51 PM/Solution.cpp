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
    TreeNode* BuildingTree(vector<int>&nums , int st , int end)
    {
        if(st > end) return nullptr;

        int mid = (st + (end-st) / 2);
        
        TreeNode* rootnode = new TreeNode(nums[mid]);
        rootnode->left = BuildingTree(nums,  st , mid-1);
        rootnode->right = BuildingTree(nums,  mid+1 , end);

        return rootnode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BuildingTree(nums , 0 , nums.size()-1);
    }
};