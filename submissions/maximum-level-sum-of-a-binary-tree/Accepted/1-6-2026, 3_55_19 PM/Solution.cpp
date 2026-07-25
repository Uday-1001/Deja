// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int sum = INT_MIN;
        int final_ans = 1;
        int level = 1;

        while(!q.empty())
        {
            int size = q.size();
            int ans = 0;

            while(size--)
            {
                TreeNode* node = q.front();
                q.pop();

                ans += node->val;

                if(node->left) q.push(node->left);
                    
                if(node->right) q.push(node->right);
            }
            if(ans > sum)
            {
                sum = ans;
                final_ans = level;
            }
            level++;
        }
    return final_ans;
    }
};