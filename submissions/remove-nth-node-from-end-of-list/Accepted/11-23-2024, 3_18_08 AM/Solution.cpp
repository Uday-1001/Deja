// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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

    int getlen(ListNode* head){
        int l = 0;
        while(head != NULL){
            l++;
            head = head->next;
        }
        return l;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len  = getlen(head);
        int delnode = len - n + 1;
        if(delnode == 1){
            // delete from head
            ListNode* temp = head;
            head=head->next;
            temp->next=NULL;
        }
        else if(delnode == len){
            // delete from tail
            ListNode* temp = head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            temp->next=NULL;
        }
        else{
            // delete from in between
            ListNode* temp = head;
            while(delnode>2){
                temp=temp->next;
                --delnode;
            }
            ListNode* curr=temp->next;
            temp->next=curr->next;
            curr->next=NULL;
        }
         return head;
    }
    
};