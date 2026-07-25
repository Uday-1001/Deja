// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode* , pair<int,int>>>q;
        map<int , map<int , multiset<int>>>mp;

        if(!root) return ans;
        //Node , {row , col} is stored in the queue
        q.push({root , {0 , 0}});

        while(!q.empty())
        {
            auto front = q.front(); q.pop();

            TreeNode* node = front.first;
            pair<int,int> coordinates = front.second;

            int row_cord = coordinates.first;
            int col_cord = coordinates.second;
            
            mp[col_cord][row_cord].insert(node->val);

            if(node->left)
            {
                q.push({node->left , {row_cord+1 , col_cord-1}});
            }
            if(node->right)
            {
                q.push({node->right , {row_cord+1 , col_cord+1}});
            }
        }

        //extracting the data from the given map -> mp
        for(auto &it: mp)
        {
            auto col_map = it.second;

            vector<int>line;
            for(auto &col_map_it : col_map)
            {
                auto multi_set = col_map_it.second;
                line.insert(line.end() , begin(multi_set) , end(multi_set));
            }
        ans.push_back(line);
        }
    return ans;
    }
};