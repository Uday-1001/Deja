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
        int sum = root->val;
        int final_ans = INT_MAX;

        while(!q.empty())
        {
            int size = q.size();
            int ans = 0;
            int level = 2;

            while(size--)
            {
                TreeNode* node = q.front();
                q.pop();

                if(node->left)
                {
                    q.push(node->left);
                    ans += node->left->val;
                }
                    
                if(node->right)
                {
                    q.push(node->right);
                    ans += node->right->val;
                } 
            }
            cout<<ans<<" ";
            if(ans > sum)
            {
                sum = ans;
                final_ans = min(final_ans , level);
            }
            level++;
        }
    return final_ans;
    }
};