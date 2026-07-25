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
    void preorder(TreeNode* root , string &s)
    {
        if(!root)
        {
            s += '#';
            return;
        }
        s += to_string(root->val) + ",";
        preorder(root->left , s);
        preorder(root->right , s);
    }

    TreeNode* deserializedTree(string &s , int &i)
    {
        if(s[i] == '#')
        {
            i++;
            return nullptr;
        }

        int sign = 1;
        if(s[i] == '-')
        {
            sign = -1;
            i++;
        }

        int num = 0;
        while(s[i] != ',')
        {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        i++;

        TreeNode* root = new TreeNode(sign * num);
        root->left = deserializedTree(s , i);
        root->right = deserializedTree(s , i);

        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        preorder(root , s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return deserializedTree(data , i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;