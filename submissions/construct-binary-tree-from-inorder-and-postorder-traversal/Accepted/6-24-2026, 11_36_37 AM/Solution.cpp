// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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

    TreeNode* Buildingtree(vector<int>&postorder , vector<int>&inorder , int st , int end)
    {
        //base condition for null nodes
        if(st > end) return nullptr;
        if(i < 0) return nullptr;

        int postorderfrontnode = postorder[i--];
        int Inorderidx = FindNode(inorder , postorderfrontnode);

        TreeNode* rootnode = new TreeNode(postorderfrontnode);
        rootnode->right = Buildingtree(postorder , inorder , Inorderidx+1 , end);
        rootnode->left = Buildingtree(postorder , inorder , st , Inorderidx-1);

        return rootnode;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        i = postorder.size()-1;
        return Buildingtree(postorder , inorder , 0 , postorder.size()-1);
    }
};