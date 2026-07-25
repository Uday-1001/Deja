// https://leetcode.com/problems/all-elements-in-two-binary-search-trees

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
    void inorderTraversal(TreeNode* root , vector<int>&inorder)
    {
        if(!root) return;

        inorderTraversal(root->left , inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right , inorder);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>l1 , l2 , ans;

        inorderTraversal(root1 , l1);
        inorderTraversal(root2 , l2);

        int i = 0 , j = 0;
        while(i < l1.size() and j < l2.size())
        {
            if(l1[i] <= l2[j]) ans.push_back(l1[i++]);
            else ans.push_back(l2[j++]);
        }
        while(i < l1.size()) ans.push_back(l1[i++]);
        while(j < l2.size()) ans.push_back(l2[j++]);
        
    return ans;
    }
};