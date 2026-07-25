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

    unordered_map<TreeNode*, vector<TreeNode*>> adj;
    unordered_map<TreeNode*, bool> visited;

    void preorder(TreeNode* root){
        // base case
        if(!root) return;
        // L 
        if(root->left){
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            preorder(root->left);
        }
        // R
        if(root->right){
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            preorder(root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        preorder(root);

        // bfs from target
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        while(!q.empty() && k > 0){
            int size = q.size();
            while(size--){
                auto src = q.front();
                q.pop();
                for(auto nbr : adj[src]){
                    if(visited[nbr] == false){
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
            k--;
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};