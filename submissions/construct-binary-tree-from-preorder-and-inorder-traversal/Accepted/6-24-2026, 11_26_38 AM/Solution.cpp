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
    int i;

    int FindNode(vector<int>&inorder , int target)
    {
        for(int i = 0 ; i<inorder.size() ; i++) if(inorder[i] == target) return i;
        return -1;
    }

    TreeNode* Buildingtree(vector<int>&preorder , vector<int>&inorder , int st , int end)
    {
        //base condition for null nodes
        if(st > end) return nullptr;
        if(i >= preorder.size()) return nullptr;

        int preorderfrontnode = preorder[i++];
        int Inorderidx = FindNode(inorder , preorderfrontnode);

        TreeNode* rootnode = new TreeNode(preorderfrontnode);
        rootnode->left = Buildingtree(preorder , inorder , st , Inorderidx-1);
        rootnode->right = Buildingtree(preorder , inorder , Inorderidx+1 , end);

        return rootnode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        i = 0;
        return Buildingtree(preorder , inorder , 0 , preorder.size()-1);
    }
};