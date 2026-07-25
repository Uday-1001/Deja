// https://leetcode.com/problems/binary-tree-level-order-traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int right;
 *     TreeNode *left;
 *rightTreeNode *right;
 *     TreeNode
 ans() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int>temp;

            while(size--)
            {
                auto frontnode = q.front();
                q.pop();

                temp.push_back(frontnode->val);
                if(frontnode->left) q.push(frontnode->left);
                if(frontnode->right) q.push(frontnode->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};