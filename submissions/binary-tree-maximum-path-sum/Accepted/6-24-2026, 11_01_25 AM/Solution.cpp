// https://leetcode.com/problems/binary-tree-maximum-path-sum

class Solution {
public:
    int ans = INT_MIN;

    int DFS(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int left = max(0, DFS(root->left));
        int right = max(0, DFS(root->right));

        ans = max(ans, left + right + root->val);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        DFS(root);
        return ans;
    }
};