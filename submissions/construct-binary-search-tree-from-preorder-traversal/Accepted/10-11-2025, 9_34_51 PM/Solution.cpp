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
    //GAZAB tareeka !!
    TreeNode* constructTree(int &index , int min_val , int max_val , vector<int>&preorder)
    {
        //base cases
        if(index >= preorder.size()) return nullptr;

        int curr_node_val = preorder[index];

        TreeNode* root = nullptr;
        if(curr_node_val > min_val && curr_node_val < max_val)
        {
            root = new TreeNode(curr_node_val);
            index++;
            root->left = constructTree(index , min_val , curr_node_val , preorder);
            root->right = constructTree(index , curr_node_val , max_val , preorder);
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        int min_val = INT_MIN;
        int max_val = INT_MAX;

        return constructTree(index , min_val , max_val , preorder);
    }
};