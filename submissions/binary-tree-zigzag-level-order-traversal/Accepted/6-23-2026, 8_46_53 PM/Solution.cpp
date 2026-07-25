// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 right     int val;
 *     TreeNode *right;
 *     TreeNode *right;
 if(!direction) reverse(begin(temp) , end(temp));
 ans.push
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>>ans;

    void ModifiedLOT(TreeNode* root)
    {
        if(!root) return;

        queue<TreeNode*>q;
        q.push(root);

        bool direction = true;
        while(!q.empty())
        {
            int size = q.size();
            vector<int>temp(size);
            for(int i = 0 ; i<size ; i++)
            {
                auto front = q.front();
                q.pop();

                int index = direction ? i : (size - i - 1);
                temp[index] = front->val;

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            ans.push_back(temp);
            direction = !direction;
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        ModifiedLOT(root);
        return ans;
    }
};