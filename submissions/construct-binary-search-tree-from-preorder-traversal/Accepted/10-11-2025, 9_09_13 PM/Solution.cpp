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
    int preorderstartidx = 0;

    void gettingInorder(vector<int>& inorder , vector<int> preorder)
    {
        sort(preorder.begin() , preorder.end());
        for(auto elem : preorder)
        {
            inorder.push_back(elem);
        }
    }

    int inorderindexfinder(vector<int>&inorder , int node)
    {
        for(int i=0 ; i<inorder.size() ; i++)
        {
            if(inorder[i] == node)
            {
                return i;
            }
        }
    return -1;
    }

    TreeNode* constructTree(vector<int>& preorder , vector<int>& inorder , int startidx , int endidx)
    {
        //base cases 
        if(preorderstartidx >= preorder.size()) return nullptr;
        if(startidx > endidx) return nullptr;

        int node = preorder[preorderstartidx++];

        //node creation of the preorder index that we got 
        TreeNode* root = new TreeNode(node);

        //find its index in the inorder to update the upcoming recursive call values
        int index_in_inorder = inorderindexfinder(inorder , node);

        //attach the left part of the tree to the root node
        root->left = constructTree(preorder , inorder , startidx , index_in_inorder - 1);

        //attach the right part of the tree to the root node
        root->right = constructTree(preorder , inorder , index_in_inorder + 1 , endidx);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder;
        gettingInorder(inorder , preorder);

        int startidx = 0;
        int endidx = preorder.size()-1;

        return constructTree(preorder , inorder , startidx , endidx);
    }
};