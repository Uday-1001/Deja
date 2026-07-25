// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected

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
    unordered_map<TreeNode* , bool>vis;
    unordered_map<TreeNode* , TreeNode*>parent;

    void parentmapping(TreeNode* root)
    {
        if(!root) return;

        if(root->left)
        {
            parent[root->left] = root;
            parentmapping(root->left);
        }
        if(root->right)
        {
            parent[root->right] = root;
            parentmapping(root->right);
        }
    }

    TreeNode* findNode(int target , TreeNode* root)
    {
        if(!root) return nullptr;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto front = q.front();
                if(front->val == target) return front;
                q.pop();

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }
    return nullptr;
    }

    int amountOfTime(TreeNode* root, int start) {
        parent[root] = nullptr;
        parentmapping(root);

        TreeNode* startnode = findNode(start , root);

        if(!startnode) return 0;
        queue<TreeNode*>q;

        q.push(startnode);
        vis[startnode] = true;

        int time = 0;

        while(!q.empty())
        {
            int size = q.size();
            bool any_infected = false;
            while(size--)
            {
                auto front = q.front(); q.pop();

                if(front->left and !vis[front->left])
                {
                    q.push(front->left);
                    vis[front->left] = true;
                    any_infected = true;
                }
                if(front->right and !vis[front->right])
                {
                    q.push(front->right);
                    vis[front->right] = true;
                    any_infected = true;
                }
                if(parent[front] and !vis[parent[front]])
                {
                    q.push(parent[front]);
                    vis[parent[front]] = true;
                    any_infected = true;
                }
            }
            if(any_infected) time++;
        }
    return time;
    }
};