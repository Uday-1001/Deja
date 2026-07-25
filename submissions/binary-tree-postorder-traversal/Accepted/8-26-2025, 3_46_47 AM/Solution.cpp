// https://leetcode.com/problems/binary-tree-postorder-traversal

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
    //2 STACK APPROACH
    vector<int>post;

    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return post;
        
        stack<TreeNode*>s1 , s2;
        s1.push(root);

        while(!s1.empty())
        {
            TreeNode* node = s1.top();
            s2.push(node);
            s1.pop();

            if(node->left != nullptr) s1.push(node->left);
            if(node->right != nullptr) s1.push(node->right);
        }
        while(!s2.empty())
        {
            post.push_back(s2.top()->val);
            s2.pop();
        }
        return post;
    }
};