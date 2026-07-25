// https://leetcode.com/problems/merge-k-sorted-lists

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
    class comparator
    {
        public:
        bool operator()(ListNode* a , ListNode* b)
        {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , comparator>pq;
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;

        int total_lists = lists.size();
        
        for(int i=0 ; i<total_lists ; i++)
        {
            if(lists[i] != nullptr)
                pq.push(lists[i]);
        }

        while(!pq.empty())
        {
            auto front = pq.top();
            pq.pop();

            dummy->next = front;
            dummy = dummy->next;

            if(front->next != nullptr)
            {
                auto next_node = front->next;
                pq.push(next_node);
            }
        }
    return head->next;
    }
};