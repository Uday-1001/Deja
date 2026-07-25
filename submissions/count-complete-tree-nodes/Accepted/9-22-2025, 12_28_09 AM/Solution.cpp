// https://leetcode.com/problems/count-complete-tree-nodes

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
    int getleftht(TreeNode* root)
    {
        int left_ht = 1;
        auto temp = root;
        while(temp)
        {
            temp = temp->left;
            left_ht++;
        }
    return left_ht;
    }

    int getrightht(TreeNode* root)
    {
        int right_ht = 0;
        auto temp = root;
        while(temp)
        {
            temp = temp->right;
            right_ht++;
        }
    return right_ht;
    }

    int countNodes(TreeNode* root) {
        //base case
        if(root == nullptr) return 0;

        int left_ht = getleftht(root->left);
        int right_ht = getrightht(root->right);

        if(left_ht == right_ht)
        {
            return pow(2 , left_ht) - 1;
        }

    return 1 + countNodes(root->left) + countNodes(root->right);
        
    }
};