// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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
    int index;

    int FindNode(vector<int>&inorder , int targetnode)
    {
        for(int i = 0 ; i<inorder.size() ; i++)
        {
            if(inorder[i] == targetnode) return i;
        }
        return -1;
    }
    TreeNode* Buildingtree(vector<int>&preorder , vector<int>&inorder , int st , int end)
    {
        if(st > end) return nullptr;
        if(index >= preorder.size()) return nullptr;

        int Inorder_index = FindNode(inorder , preorder[index]);
        TreeNode* rootnode = new TreeNode(preorder[index++]);

        rootnode->left = Buildingtree(preorder , inorder , st , Inorder_index-1);
        rootnode->right = Buildingtree(preorder , inorder , Inorder_index+1 , end);

        return rootnode;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        index = 0;
        vector<int>inorder = preorder;

        sort(begin(inorder) , end(inorder));
        return Buildingtree(preorder , inorder , 0 , preorder.size()-1);
    }
};