// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int getlen(ListNode* head)
    {
        int len = 0;
        ListNode* temp = head;
        while(temp)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }

    TreeNode* construct(ListNode*&head , int len)
    {
        if(!head || len <= 0) return nullptr;
        
        //constructing tree using the half nodes 
        TreeNode* left_subtree = construct(head , len/2);

        //creating the root node
        TreeNode* root = new TreeNode(head->val);
        root->left = left_subtree;

        //select the next node of the LL
        head = head->next;

        //as half of the nodes and root node are created so nodes remaining = n-(n/2+1)
        TreeNode* right_subtree = construct(head , len-(len/2+1));
        root->right = right_subtree;

        return root;
    } 

    TreeNode* sortedListToBST(ListNode* head) {
        int len = getlen(head);
        return construct(head , len);
    }
};