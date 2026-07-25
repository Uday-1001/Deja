// https://leetcode.com/problems/create-binary-tree-from-descriptions

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
    unordered_map<int , vector<pair<int,int>>>adj;

    void BuildTree(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto parent = q.front();
                q.pop();

                for(auto &child : adj[parent->val])
                {
                    auto isleft = child.first;
                    auto childval = child.second;

                    TreeNode* childnode = new TreeNode(childval);

                    if(isleft == 1) parent->left = childnode;
                    else parent->right = childnode;

                    q.push(childnode);
                }
            }
        }
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int rootnode = -1;
        unordered_map<int , bool>nodes;

        for(auto it : descriptions) 
        {
            nodes[it[0]] = true;
            nodes[it[1]] = true;
        }

        for(auto it : descriptions)
        {
            int parent = it[0];
            int child = it[1];
            int isleft = it[2];

            adj[parent].push_back({isleft , child});
            nodes[child] = false;
        }

        for(auto it : nodes) 
        {
            if(it.second == true) 
            {
                rootnode = it.first;
                break;
            }
        }

        TreeNode* root = new TreeNode(rootnode);

        BuildTree(root);

        return root;
    }
};