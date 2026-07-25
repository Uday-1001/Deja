// https://leetcode.com/problems/serialize-and-deserialize-bst

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void inorderTraversal(TreeNode* root , string &inorder)
    {
        if(!root) return;
        inorderTraversal(root->left , inorder);
        inorder.push_back(root->val + '0');
        inorderTraversal(root->right , inorder);        
    }

    TreeNode* makingTree(string &inorder , int s , int e)
    {
        if(s > e) return nullptr;
        int mid = s + (e-s)/2;

        TreeNode* rootnode = new TreeNode(inorder[mid] - '0');
        
        rootnode->left = makingTree(inorder , s , mid - 1);
        rootnode->right = makingTree(inorder , mid + 1 , e);

        return rootnode;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string inorder = "";
        inorderTraversal(root , inorder);
        return inorder;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return makingTree(data , 0 , data.size()-1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;