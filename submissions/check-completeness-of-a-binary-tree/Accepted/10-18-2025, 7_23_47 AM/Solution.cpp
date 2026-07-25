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
        //Babbar Bhaiya's Dimaag !!
        queue<TreeNode*>q;

        if(!root) return true;
        q.push(root);

        bool null_found = false;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            if(node == nullptr)
            {
                //invalid node 
                null_found = true;
            }
            else
            {
                //got a valid node 
                if(null_found == true)
                {
                    return false;
                }
                else
                {
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
    return true;
    }
};