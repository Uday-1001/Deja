// https://leetcode.com/problems/delete-node-in-a-bst

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

    //to calculate the inorder predecessor
    int getpre(TreeNode* root)
    {
        if(!root) return -1;
    
        while(root->right)
        {
            root = root->right;
        }
    return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        if(root->val == key)
        {
            //we have to handle 4 cases that are :-

            //case 1 - no children of a node 
            if(!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }
            //case 2 - left child only exists
            if(root->left && !root->right)
            {
                TreeNode* leftchild = root->left;
                root->left = nullptr;
                delete root;
                return leftchild;
            }
            //case 3 - right child only exists
            if(!root->left && root->right)
            {
                TreeNode* rightchild = root->right;
                root->right = nullptr;
                delete root;
                return rightchild;
            }
            //case 4 - both left and right child exist , so replace the root with inorder predecessor/successor
            if(root->left && root->right)
            {
                int inorderPredecessor = getpre(root->left);
                root->val = inorderPredecessor;
                root->left = deleteNode(root->left , inorderPredecessor);
                return root;
            }
        }
        else
        {
            if(root->val < key)
            {
                //go to right direction of the BST
                root->right = deleteNode(root->right , key);
            }
            else
            {
                //go to left direction of the BST
                root->left = deleteNode(root->left , key);
            }
        }
    return root; 
    }
};