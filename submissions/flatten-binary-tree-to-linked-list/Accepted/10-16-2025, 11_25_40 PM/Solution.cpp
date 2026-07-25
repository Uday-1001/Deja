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
    //Doing By Morris Traversal Approach
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while(curr)
        {
            if(curr->left != nullptr)
            {
                TreeNode* predecessor = curr->left;
                while(predecessor->right)
                {
                    predecessor = predecessor->right;
                }
                predecessor->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};