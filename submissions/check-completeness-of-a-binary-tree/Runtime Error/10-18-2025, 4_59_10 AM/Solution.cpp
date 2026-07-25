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
        queue<pair<TreeNode* , int>>q;

        int count = 0;
        
        if(!root) return false;
        q.push({root , 1});
        count++;

        int last_numbering = -1;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto node = q.front().first;
                auto numbering = q.front().second;
                last_numbering = numbering;
                q.pop();

                if(node->left)
                {
                    q.push({node->left , 2*numbering});
                    count++;
                }
                if(node->right)
                {
                    q.push({node->right , 2*numbering + 1});
                    count++;
                }
            }
        }
        return (last_numbering == count);
    }
};