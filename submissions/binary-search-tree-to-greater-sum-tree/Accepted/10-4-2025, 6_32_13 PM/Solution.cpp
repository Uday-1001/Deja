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

    TreeNode* updateTree(vector<int>&inorder , TreeNode* root , int &index)
    {
        if(!root) return nullptr;

        updateTree(inorder , root->left , index);
        root->val = inorder[index];
        index++;
        updateTree(inorder , root->right , index);

        return root;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>inorder;
        getinorder(root , inorder);

        int n = inorder.size();

        vector<int>inordersum(n);
        //calculate the sum of the inorder array acc. to given rules
        int sum = 0;
        for(int i=n-1 ; i>=0; i--)
        {
           sum += inorder[i];
           inordersum[i] = sum;
        }
        inorder = inordersum;
        
        //update the tree using the inorder traversal again
        int index = 0;
        updateTree(inorder , root , index);
        return root;

    }
};