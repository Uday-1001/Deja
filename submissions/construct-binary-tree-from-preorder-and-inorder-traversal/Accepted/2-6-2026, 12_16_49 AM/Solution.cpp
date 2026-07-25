// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    int prestart = 0;
    int getindex(vector<int>&inorder , int nodeval)
    {
        for(int i = 0 ; i<inorder.size() ; i++) if(inorder[i] == nodeval) return i;
        return -1;
    }

    TreeNode* makingTree(vector<int>& preorder, vector<int>& inorder , int start , int end)
    {
        //base cases
        if(prestart >= preorder.size()) return nullptr;
        if(start > end) return nullptr;

        int node = preorder[prestart++];

        int indexinInorder = getindex(inorder , node);
        TreeNode* root = new TreeNode(node);

        root->left = makingTree(preorder , inorder , start , indexinInorder - 1);
        root->right = makingTree(preorder , inorder , indexinInorder + 1 , end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int st = 0;
        int end = inorder.size()-1;

        return makingTree(preorder , inorder , st , end);
    }
};