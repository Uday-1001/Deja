// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;

        if(!root) return ans;
        q.push(root);

        bool direction_LtoR = true;

        while(!q.empty())
        {
            int size = q.size();
            vector<int>level;
            
            for(int i=0 ; i<size ; i++)
            {
                auto front = q.front();
                q.pop();
                
                level.push_back(front->val);
                if(!direction_LtoR)
                {
                    reverse(begin(level) , end(level));
                }

                if(front->left)
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }
            }
        ans.push_back(level);
        direction_LtoR = !direction_LtoR;
        }
    return ans;       
    }
};