// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree

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
    void getinorder(TreeNode* root , vector<int>&inorder)
    {
        if(!root) return;
        getinorder(root->left , inorder);
        inorder.push_back(root->val);
        getinorder(root->right , inorder);
    }
    
    TreeNode* updatetree(vector<int>&inorderupdated , TreeNode* root , int &i)
    {
        if(!root) return nullptr;   
        
        updatetree(inorderupdated , root->left , i);
        root->val = inorderupdated[i++];
        updatetree(inorderupdated , root->right , i);
        
        return root;   
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>inorder;
        getinorder(root , inorder);
        
        vector<int>inorderupdated(inorder.size());
        int sum = 0;
        for(int i=inorder.size()-1 ; i>=0 ; i--)
        {
            sum += inorder[i];
            inorderupdated[i] = sum;
        }
        
        int i = 0;
        updatetree(inorderupdated , root , i);
        return root;
    }
};