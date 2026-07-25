// https://leetcode.com/problems/symmetric-tree

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
    void makebabiesleft(TreeNode* root , vector<int>&vec)
    {
        if(!root)
        {
            vec.push_back(-200);
            return;
        } 

        vec.push_back(root->val);
        makebabiesleft(root->left , vec);
        makebabiesleft(root->right , vec);
    }
    void makebabiesright(TreeNode* root , vector<int>&vec)
    {
        if(!root) 
        {
            vec.push_back(-200);
            return;
        }

        vec.push_back(root->val);
        makebabiesright(root->right , vec);
        makebabiesright(root->left , vec);
    }

    bool isSymmetric(TreeNode* root) {
        vector<int>left;
        vector<int>right;

        makebabiesleft(root , left);
        makebabiesright(root , right);

        return left == right;
    }
};