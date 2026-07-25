// https://leetcode.com/problems/rotate-list

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
    int length(ListNode* root)
    {
        ListNode* temp = root;
        int len = 0;
        while(temp != nullptr)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* findNode(ListNode* head , int k , int len)
    {
        ListNode* temp = head;
        int req_steps = len - k - 1;

        while(req_steps--) temp = temp->next;

        ListNode* tail = temp;
        return tail;
    }


    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        if(k == 0) return head;

        int len = length(head);
        k %= len;

        ListNode* targetNode = findNode(head , k , len);
        if(targetNode->next == nullptr) return head;

        ListNode* nextnode = targetNode->next;
        targetNode->next = nullptr;

        ListNode* temp = nextnode;
        while(temp->next != nullptr) temp = temp->next;
        
        ListNode* lastnode = temp;
        lastnode->next = head;
    
        return nextnode;
    }
};