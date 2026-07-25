// https://leetcode.com/problems/find-duplicate-subtrees

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
    vector<TreeNode*>ans;
    unordered_map<string,int>mapping;

    string encoding(TreeNode* root)
    {
        if(!root) return "Null";

        string node_string = to_string(root->val);
        string left_string = encoding(root->left);
        string right_string = encoding(root->right);

        string result = left_string + node_string + right_string;

        if(mapping.find(result) != mapping.end())
        {
            if(mapping[result] == 1)
            {
                ans.push_back(root);
            }
            mapping[result]++;
        }
        else
        {
            mapping[result]++;
        }
    return result;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        encoding(root);
        return ans;
    }
};