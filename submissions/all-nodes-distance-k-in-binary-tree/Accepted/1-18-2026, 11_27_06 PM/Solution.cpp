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
    unordered_map<TreeNode* , TreeNode*>parent;
    unordered_map<TreeNode* , bool>vis;

    void parentmap(TreeNode* root)
    {
        //base case to stop infinite mapping 
        if(!root) return;
        if(root->left)
        {
            parent[root->left] = root;
            parentmap(root->left);
        }
        if(root->right)
        {
            parent[root->right] = root;
            parentmap(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parentmap(root);

        queue<TreeNode*>q;
        q.push(target);
        vis[target] = true;
        parent[root] = nullptr;

        while(!q.empty())
        {
            int size = q.size();
            if(k == 0) break;

            while(size--)
            {
                auto frontnode = q.front(); q.pop();

                if(frontnode->left and !vis[frontnode->left])
                {
                    q.push(frontnode->left);
                    vis[frontnode->left] = true;
                }
                if(frontnode->right and !vis[frontnode->right])
                {
                    q.push(frontnode->right);
                    vis[frontnode->right] = true;
                }
                if(parent[frontnode] and !vis[parent[frontnode]])
                {
                    q.push(parent[frontnode]);
                    vis[parent[frontnode]] = true;
                }
            }
            k--;
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};