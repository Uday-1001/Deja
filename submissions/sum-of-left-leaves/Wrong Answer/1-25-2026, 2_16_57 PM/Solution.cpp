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
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int>level;
            while(size--)
            {
                auto front = q.front();  
                q.pop();

                level.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(level);
        }

        int sum = 0;
        for(auto vec : ans)
        {
            if(vec.size() == 1) continue;
            else sum += vec.front();
        }
        return sum;
    }
};