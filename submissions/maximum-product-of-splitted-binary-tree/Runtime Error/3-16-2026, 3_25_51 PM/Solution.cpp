// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

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
    using ll = long long;
    int mod = 1e9 + 7;
    
    int summedUp(TreeNode* root)
    {
        if(!root) return 0;
        int sum = root->val + summedUp(root->left) + summedUp(root->right);
        
        return root->val = sum;
    }

    int maxProduct(TreeNode* root) {
        int total_sum = summedUp(root);
        queue<TreeNode*>q;
        q.push(root);

        ll maxi = LLONG_MIN;
        while(!q.empty())
        {
            auto front = q.front(); q.pop();
            ll prod = (total_sum - front->val) * front->val;
            maxi = max<ll>(maxi , prod);

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    return maxi % mod;
    }
};