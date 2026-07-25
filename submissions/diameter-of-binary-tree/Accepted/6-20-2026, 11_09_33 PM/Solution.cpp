// https://leetcode.com/problems/diameter-of-binary-tree

class Solution {
public:
    int diameter = 0;

    int solve(TreeNode* root)
    {
        if(!root) return 0;

        int leftht = solve(root->left);
        int rightht = solve(root->right);

        diameter = max(diameter, leftht + rightht);

        return max(leftht, rightht) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        solve(root);
        return diameter;
    }
};