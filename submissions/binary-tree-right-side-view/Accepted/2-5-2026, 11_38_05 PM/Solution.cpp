// https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        vector<vector<int>>bfs;

        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int>lvl;
            
            while(size--)
            {
                auto front = q.front(); q.pop();
                lvl.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            bfs.push_back(lvl);
        }

        for(auto it : bfs)
        {
            ans.push_back(it.back());
        }
        return ans;
    }
};