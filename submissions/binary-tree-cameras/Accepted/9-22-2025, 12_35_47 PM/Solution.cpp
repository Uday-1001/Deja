// https://leetcode.com/problems/binary-tree-cameras

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
    int solve(TreeNode* root , int& cameras)
    {
        //base case
        if(!root) return 1;
        
        auto left = solve(root->left , cameras);
        auto right = solve(root->right , cameras);

        if(left == 0 || right == 0)
        {
            //iska mtlb neeche se koi coverage nhi hai -> install a camera
            cameras++;
            return 2;
        }
        if(left == 2 || right == 2)
        {
            //iska mtlb i am covered by my child
            return 1;
        }
        //else i am not covered by any means
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        int root_state = solve(root , cameras);
        
        if(root_state == 0)
        {
            cameras++;
        }
        return cameras;
    }
};