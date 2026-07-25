// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

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
    ListNode* ReverseNodes(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr)
        {
            auto frontnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = frontnode;
        }
        return prev;
    }

    int getlen(ListNode* head)
    {
        ListNode* temp = head;
        int len = 0;

        while(temp != nullptr)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    int pairSum(ListNode* head) {
        int len = getlen(head);
        int half = len / 2 - 1;

        ListNode* temp = head;
        while(half--) temp = temp->next;

        ListNode* nextnode = temp->next;
        auto reversehead = ReverseNodes(nextnode);
        temp->next = reversehead;

        ListNode* first = head;
        ListNode* second = reversehead;

        int ans = 0;

        while(second != nullptr)
        {
            ans = max(ans , (first->val + second->val));
            first = first->next;
            second = second->next;
        }

        return ans;
    }
};