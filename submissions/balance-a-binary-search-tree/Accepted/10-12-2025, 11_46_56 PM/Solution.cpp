// https://leetcode.com/problems/balance-a-binary-search-tree

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

    TreeNode* constructTree(vector<int>&inorder , int start , int end)
    {
        if(start > end) return nullptr;

        int mid = (start + end)/2;
        int node_val = inorder[mid];

        //create the node for the node value 
        TreeNode* root = new TreeNode(node_val);
        
        //attach the root to the left subtree
        root->left = constructTree(inorder , start , mid-1);
        //attach the root to the right subtree
        root->right = constructTree(inorder , mid+1 , end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        getinorder(inorder , root);

        int n = inorder.size();

        return constructTree(inorder , 0 , n-1);          
    }
};