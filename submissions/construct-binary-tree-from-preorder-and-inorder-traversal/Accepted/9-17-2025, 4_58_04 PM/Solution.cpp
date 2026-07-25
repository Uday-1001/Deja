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
    int getidxinInorder(vector<int>& inorder , int node)
    {
        for(int i=0 ; i<inorder.size() ; i++)
        {
            if(inorder[i] == node)
                return i;
        }
    return -1;
    }

    TreeNode* construction(vector<int>& preorder, vector<int>& inorder , int& preorderstartidx , int inorderstartidx , int  inorderendidx)
    {
        //base case
        if(preorderstartidx >= preorder.size()) return nullptr;

        if(inorderstartidx > inorderendidx) return nullptr;

        //ek case hum solve karenge -> first ie root node ka construction.
        int node = preorder[preorderstartidx];
        preorderstartidx ++;
        TreeNode* root = new TreeNode(node);

        int idx_of_currnode_in_inorder = getidxinInorder(inorder , node);

        root->left = construction(preorder , inorder , preorderstartidx , inorderstartidx , idx_of_currnode_in_inorder-1);

        root->right = construction(preorder , inorder , preorderstartidx ,                       idx_of_currnode_in_inorder+1 , inorderendidx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderstartidx = 0;
        int inorderstartidx = 0;
        int inorderendidx = inorder.size()-1;

        return construction(preorder , inorder , preorderstartidx , inorderstartidx , inorderendidx);
    }
};