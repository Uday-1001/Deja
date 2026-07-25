// https://leetcode.com/problems/binary-tree-inorder-traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        //Corrected Morris Traversal 
        vector<int>ans;

        TreeNode* curr = root;
        while(curr)
        {
            //if the left child is null then , follow L N R
            if(curr->left == nullptr)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                //if the left child != null then find its IP(inorder predecessor) 
                TreeNode* IP = curr->left;
                while(IP->right && IP->right != curr)
                {
                    IP = IP->right;
                }
                //check if the IP->right is null ? then attach it to root (create link to backtrack to root)
                if(IP->right == nullptr)
                {
                    IP->right = curr;
                    curr = curr->left;
                }
                else
                {
                    //means link is already made , so destroy it.
                    IP->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};