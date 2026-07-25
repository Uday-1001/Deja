// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    int bfs(TreeNode* root)
    {
        queue<pair<TreeNode* , int>>q;
        if(!root) return 0;
        q.push({root , 1});

        while(!q.empty())
        {
           auto[front , depth] = q.front() ; q.pop();

           if(!front->left && !front->right) return depth;
           
           if(front->left) q.push({front->left , depth + 1});
           if(front->right) q.push({front->right , depth + 1}); 
        }
        return 0;
    }

    int minDepth(TreeNode* root) {
        return bfs(root);
    }
};