// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        queue<TreeNode*>q;
        
        if(root == nullptr) return ans;

        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int>curr_lvl;

            for(int i=0 ; i<size ; i++)
            {
                TreeNode* curr_node = q.front();
                q.pop(); 

                if(curr_node->left != nullptr)
                q.push(curr_node->left);

                if(curr_node->right != nullptr)
                q.push(curr_node->right);

                curr_lvl.push_back(curr_node->val);
            }
            ans.push_back(curr_lvl);  
        }
    return ans;
    }
};