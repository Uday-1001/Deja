// https://leetcode.com/problems/flatten-binary-tree-to-linked-list

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
    void flatten(TreeNode* root) {
        TreeNode* currnode = root;

        while(currnode != nullptr)
        {
            if(currnode->left != nullptr)
            {
                TreeNode* pre = currnode->left;
                //to find the predecessor
                while(pre->right != nullptr) pre = pre->right;
                //connect the links with currnode 
                pre->right = currnode->right;
                currnode->right = currnode->left;
                currnode->left = nullptr;
            }
            currnode = currnode->right;
        }
    }
};