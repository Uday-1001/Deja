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
    int getlen(ListNode* head)
    {
        ListNode* temp = head;
        int len = 0;
        while(temp)
        {
            temp = temp->next;
            len++;
        }
    return len;
    }

    ListNode* findnode(ListNode* head , int count)
    {
        ListNode* temp = head;
        int cnt = 1;
        while(cnt != count)
        {
            temp = temp->next;
            cnt++;
        }
        return temp;
    } 

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or k==0) return head;
        int len = 1;

        ListNode* tail = head;
        while(tail->next)
        {
            tail = tail->next;
            len++;
        }

        k %= len;
        if(k == 0) return head;

        tail->next = head;
        ListNode* nextTail = findnode(head , len-k);
        ListNode* nextHead = nextTail->next;
        nextTail->next = nullptr;

    return nextHead;
    }
};