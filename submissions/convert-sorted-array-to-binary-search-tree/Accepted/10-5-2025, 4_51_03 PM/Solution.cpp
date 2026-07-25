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
    TreeNode* constructTree(vector<int>&nums , int start , int end)
    {
        if(start > end) return nullptr;

        int mid = start + (end-start)/ 2;
        int root_val = nums[mid];

        TreeNode* root_node = new TreeNode(root_val);
        root_node->left = constructTree(nums , start , mid-1);
        root_node->right = constructTree(nums , mid+1 , end);

        return root_node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        TreeNode* root = constructTree(nums , 0 , nums.size()-1);
        return root;
    }
};