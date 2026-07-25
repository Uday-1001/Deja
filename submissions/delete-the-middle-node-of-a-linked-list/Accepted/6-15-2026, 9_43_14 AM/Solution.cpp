// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

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
class Solution {
public:
    int getlen(ListNode* head)
    {
        auto temp = head;
        int len = 0;

        while(temp)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* deleteMiddle(ListNode* head) {        
        int len = getlen(head);
        
        if(len == 1) return nullptr;

        auto nodebeforemiddle = head;
        int before_middle_pos = len/2 - 1;

        for(int i = 0 ; i<before_middle_pos ; i++) nodebeforemiddle = nodebeforemiddle->next;
        
        auto middlenode = nodebeforemiddle->next;
        nodebeforemiddle->next = middlenode->next;
        middlenode->next = nullptr;
        delete(middlenode);

        return head;
    }
};