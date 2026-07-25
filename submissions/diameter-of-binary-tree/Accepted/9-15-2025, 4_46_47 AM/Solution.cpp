// https://leetcode.com/problems/diameter-of-binary-tree

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
    int getheight(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int left_height = getheight(root->left);
        int right_height = getheight(root->right);

        return 1 + max(left_height , right_height);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        //when answer is made up of only left subtree
        int option1 = diameterOfBinaryTree(root->left);

        //when answer is made up only of right subtree
        int option2 = diameterOfBinaryTree(root->right);

        //when both left and right subtree with root node are involved
        int option3 = getheight(root->left) + getheight(root->right);

        return max(option1 , max(option2 , option3));
    }
};