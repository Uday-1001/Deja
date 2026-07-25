// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another

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
    unordered_map<TreeNode* , TreeNode*>parent;
    unordered_map<TreeNode* , bool>vis;

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

    TreeNode* findlocation(int val , TreeNode* root)
    {
        if(!root) return nullptr;
        if(root->val == val) return root;

        TreeNode* left = findlocation(val , root->left);
        if(left != nullptr) return left;

        TreeNode* right = findlocation(val , root->right);
        if(right != nullptr) return right;

        return nullptr;
    }

    void DFS(TreeNode* st , TreeNode* end , string &path , string &ans)
    {
        //base case
        if(!st) return;
        if(st == end)
        {
            ans = path;
            return;
        }

        //going left
        if(st->left and !vis[st->left])
        {
            path.push_back('L');
            vis[st->left] = true;
            DFS(st->left , end , path , ans);
            path.pop_back();
            vis[st->left] = false;
        }

        //going right
        if(st->right and !vis[st->right])
        {
            path.push_back('R');
            vis[st->right] = true;
            DFS(st->right , end , path , ans);
            path.pop_back();
            vis[st->right] = false;
        }

        //going up
        if(parent[st] and !vis[parent[st]])
        {
            path.push_back('U');
            vis[parent[st]] = true;
            DFS(parent[st] , end , path , ans);
            path.pop_back();
            vis[parent[st]] = false;
        }
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        parent[root] = nullptr;
        parentmapping(root);

        //to find the location of the given values of start and end nodes
        auto st = findlocation(startValue , root);
        auto end = findlocation(destValue , root);
        vis[st] = true;

        //buiding the path string
        string path = "";
        string ans = "";

        DFS(st , end , path , ans);
        return ans;
    }
};