// https://leetcode.com/problems/sum-of-left-leaves

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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int sum = 0;
        
        while(!q.empty())
        {
            auto front = q.front();  
            q.pop();

            if(front->left and !front->left->left and !front->left->right)
            {
                sum += front->left->val;
            }

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    return sum;
    }
};