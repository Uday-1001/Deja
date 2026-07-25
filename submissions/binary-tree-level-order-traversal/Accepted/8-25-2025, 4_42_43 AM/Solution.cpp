// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        
        // if we get the node as null it means that we have reached the leaf node.
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        
        //if the queue is empty then there are no nodes associated to it.
        while(!q.empty())
        {
            int size = q.size();
            vector<int>level;
            
            for(int i=0 ; i<size ; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                //if there exists the left and the right of the node then the nodes are pushed in queue.
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                
                level.push_back(node->val);
            }
            //here we get level for every node we traverse in the level vector
            ans.push_back(level);
        }
        return ans;
    }
};