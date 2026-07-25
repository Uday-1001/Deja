// https://leetcode.com/problems/find-bottom-left-tree-value

class Solution {
public:
    int ans;
    int maxLevel = -1;

    void solve(TreeNode* root, int level)
    {
        if(root == nullptr) return;

        if(level > maxLevel)
        {
            maxLevel = level;
            ans = root->val;
        }

        solve(root->left, level + 1);
        solve(root->right, level + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};