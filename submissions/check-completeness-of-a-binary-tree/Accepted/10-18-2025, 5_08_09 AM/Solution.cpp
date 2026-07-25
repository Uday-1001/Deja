// https://leetcode.com/problems/check-completeness-of-a-binary-tree

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
    bool isCompleteTree(TreeNode* root) {
        queue<pair<TreeNode* , unsigned int>>q;

        

        if(!root) return true;
        q.push({root , 1});

        unsigned int count = 0;
        unsigned int last_numbering = -1;

        while(!q.empty())
        {
            auto node = q.front().first;
            unsigned int numbering = q.front().second;
            q.pop();

            last_numbering = numbering;
            count++;

            if(node->left)
            {
                q.push({node->left , 2*numbering});
            }
            if(node->right)
            {
                q.push({node->right , 2*numbering + 1});
            }
        }
        return (last_numbering == count);
    }
};