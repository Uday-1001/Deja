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
        Node* tailnode = it;

        while(it)
        {
            if(it->child)
            {
                Node* foundtail = solve(it->child);

                //joining of the found tail node to the required nodes
                Node* temp = it->next;
                it->next = it->child;
                it->next->prev = it;
                foundtail->next = temp;
                if(temp != NULL)
                {
                    temp->prev = foundtail;
                }
                it->child = NULL;
            }
            tailnode = it;
            it = it->next;
        }
    return tailnode;
    }

    Node* flatten(Node* head) 
    {
        if(head == NULL) return nullptr;
        solve(head);
        return head;
    }
};