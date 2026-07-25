// https://leetcode.com/problems/deepest-leaves-sum

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
    void bfs(TreeNode* root , vector<vector<int>>&ans)
    {
        if(!root) return;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int>level;

            while(size--)
            {
                auto node = q.front();
                q.pop();

                level.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
    }
    
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>>ans;

        bfs(root , ans);
        vector<int>v = ans[ans.size() - 1];
        int sum = accumulate(v.begin() , v.end() , 0);
        return sum;
    }
};