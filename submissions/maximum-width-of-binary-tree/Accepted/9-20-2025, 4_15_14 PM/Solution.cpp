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
        if (!root) return 0;

        unsigned int maxi = 0;
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root, 0});

        while (!q.empty()) 
        {
            int size = q.size();
            unsigned int left_most = q.front().second;
            unsigned int right_most = q.back().second;

            maxi = max(maxi, (unsigned int)(right_most - left_most + 1));

            for (int i = 0; i < size; i++) 
            {
                auto front = q.front();
                q.pop();

                TreeNode* node = front.first;
                unsigned int index = front.second;

                if (node->left) 
                    q.push({node->left, 2 * index});
                if (node->right) 
                    q.push({node->right, 2 * index + 1});
            }
        }
        return (int)maxi;
    }
};