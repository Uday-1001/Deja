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
        //Corrupted Morris Traversal (Runs and Also Submits)
        //Shows Segmentation Fault on GFG due to infinte loop creation !!
        vector<int>ans;
        TreeNode* curr = root;

        while(curr != nullptr)
        {
            //ek baar saara left ka kaam ho gya to right jao
            if(curr->left == nullptr)
            {
                //agar leftchild he null ho means we reached the first inorder element
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                //means that the left child is not null so we get to the left child's rightmost chid
                TreeNode* leftchild = curr->left;
                while(leftchild->right != nullptr)
                {
                    leftchild = leftchild->right;
                }
                //we reach the rightmost child of the leftchild of curr node
                leftchild->right = curr;
                //here we destroy the links of curr node and the left child
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }
        }
    return ans;
    }
};