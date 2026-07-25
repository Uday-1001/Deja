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
    bool palindrome(vector<int>&level)
    {
        int i = 0;
        int j = level.size()-1;

        while(i < j)
        {
            if(level[i] != level[j]) return false;
            else 
            {
                i++ ; j--;
            }
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int>level;

            while(size--)
            {
                auto front = q.front();
                q.pop();

                if(front != nullptr)
                {
                    level.push_back(front->val);
                    q.push(front->left);
                    q.push(front->right);
                }
                else level.push_back(INT_MIN);
            }
            if(!palindrome(level)) return false;
        }
    return true;
    }
};