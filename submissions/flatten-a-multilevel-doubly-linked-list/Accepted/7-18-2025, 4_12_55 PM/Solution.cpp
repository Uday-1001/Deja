// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* head)
    {
        Node* it = head;
        Node* dummy = it;

        while(it)
        {
            if(it->child)
            {
                Node* child_tail = solve(it->child);
                //when the function call comes back to the stack function again 
                Node* temp = it->next;
                it->next = it->child;
                it->next->prev = it;
                child_tail->next = temp;
                if(temp) 
                {
                    temp->prev = child_tail;
                }
                it->child = NULL;
            }
            dummy = it;
            it = it->next;
        }
        return dummy;
    }
    Node* flatten(Node* head) {
        if(head == NULL) return nullptr;
        solve(head);
        return head;

    }
};