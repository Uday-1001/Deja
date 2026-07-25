// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<TreeNode*,TreeNode*>mp;

    void parentmapping(TreeNode* root)
    {
        //performing the inorder traversal to store the parent 
        if(root == nullptr) return;

        if(root->left)
        {
            mp[root->left] = root;
            parentmapping(root->left);
        }

        if(root->right)
        {
            mp[root->right] = root;
            parentmapping(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parentmapping(root);
        
        queue<TreeNode*>q;
        unordered_set<int> visited;

        q.push(target);
        visited.insert(target->val);
        
        int level = 0;
        while(!q.empty())
        {
            int size = q.size();

            if(level == k) break;

            while(size--)
            {
                auto curr = q.front();
                q.pop();

                if(curr->left != NULL && !visited.count(curr->left->val))
                {
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }
                if(curr->right != NULL && !visited.count(curr->right->val))
                {
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }
                if(mp.count(curr) && !visited.count(mp[curr]->val))
                {
                    q.push(mp[curr]);
                    visited.insert(mp[curr]->val);
                }
            }
                level++;
        }
        //store the answer
        vector<int>ans;
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
    return ans;
    }
};