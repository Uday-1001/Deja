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

    int getidxinInorder(vector<int>& inorder , int node)
    {
        for(int i=0 ; i<inorder.size() ; i++)
        {
            if(inorder[i] == node)
                return i;
        }
    return -1;
    }

    TreeNode* construction(vector<int>& postorder, vector<int>& inorder  , int &postorderstartidx , int inorderstartidx , int  inorderendidx)
    {
        //base case
        if(postorderstartidx < 0) return nullptr;

        if(inorderstartidx > inorderendidx) return nullptr;

        //ek case hum solve karenge -> first ie root node ka construction.
        int node = postorder[postorderstartidx];
        postorderstartidx --;
        TreeNode* root = new TreeNode(node);

        int idx_of_currnode_in_inorder = getidxinInorder(inorder , node);

        root->right = construction(postorder , inorder , postorderstartidx , idx_of_currnode_in_inorder+1 , inorderendidx);
        root->left = construction(postorder , inorder , postorderstartidx , inorderstartidx , idx_of_currnode_in_inorder-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inorderstartidx = 0;
        int inorderendidx = inorder.size()-1;
        int postorderstartidx = postorder.size()-1;

        return construction(postorder , inorder , postorderstartidx , inorderstartidx , inorderendidx);
    }
};