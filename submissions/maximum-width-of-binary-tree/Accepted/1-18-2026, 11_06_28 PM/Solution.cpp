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
    using ui = unsigned int;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode* , ui>>q;
        q.push({root , 0});
        ui maxwidth = 0;

        while(!q.empty())
        {
            int size = q.size();
            auto leftchild = q.front().second;
            auto rightchild = q.back().second;
            
            maxwidth = max<ui>(maxwidth , (rightchild - leftchild + 1));

            while(size--)
            {
                auto[node , index] = q.front(); q.pop();

                ui leftchildidx = 2 * index + 1;
                ui rightchildidx = 2 * index + 2;
                
                if(node->left) q.push({node->left , leftchildidx});
                if(node->right) q.push({node->right , rightchildidx});
            }
        }
        return maxwidth;
    }
};