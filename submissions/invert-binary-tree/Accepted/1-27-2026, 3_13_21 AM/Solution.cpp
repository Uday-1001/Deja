// https://leetcode.com/problems/invert-binary-tree

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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                auto temp = node->left;
                node->left = node->right;
                node->right = temp;
            }
        }
        return root;
    }
};