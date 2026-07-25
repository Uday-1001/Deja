// https://leetcode.com/problems/find-bottom-left-tree-value

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
    int solve(TreeNode* root)
    {
        vector<vector<int>>ans;
        if(!root) return 0;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int>temp;

            while(size--)
            {
                auto front = q.front();
                q.pop();

                temp.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(temp);
        }
        return ans.back()[0];
    }

    int findBottomLeftValue(TreeNode* root) {
        return solve(root);
    }
};