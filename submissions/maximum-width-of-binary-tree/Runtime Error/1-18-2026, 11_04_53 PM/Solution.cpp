// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , int>>q;
        q.push({root , 0});
        int maxwidth = 0;

        while(!q.empty())
        {
            int size = q.size();
            auto leftchild = q.front().second;
            auto rightchild = q.back().second;
            
            maxwidth = max(maxwidth , (rightchild - leftchild + 1));

            while(size--)
            {
                auto[node , index] = q.front(); q.pop();

                int leftchildidx = 2 * index + 1;
                int rightchildidx = 2 * index + 2;
                
                if(node->left) q.push({node->left , leftchildidx});
                if(node->right) q.push({node->right , rightchildidx});
            }
        }
        return maxwidth;
    }
};