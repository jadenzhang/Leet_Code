/*
Question# + Difficulty + Topic + Company + Similar_Question
[148] [Sort List] [Medium] [Linked List Sort  ] 
[] 
[21 75 147].cpp
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        
        ListNode* n1 = head;
        ListNode* n2 = head;
        ListNode* pre = head;
        //p1 move one step, p2 two steps
        while(n2 && n2->next)
        {
            pre = n1;
            n1 = n1->next;
            n2 = n2->next->next;
        }
        // change pre next to null to make two sublist(head to pre, p1 to p2)
        pre->next = NULL;
        
        // do these two list sort and merge
        ListNode* tmp1 = sortList(head);
        ListNode* tmp2 = sortList(n1);
        
        return my_merge(tmp1,tmp2);
    }
    ListNode* my_merge(ListNode* n1,ListNode* n2)
    {
        if(!n1) return n2;
        if(!n2) return n1;
        
        if(n1->val<n2->val)
        {
            n1->next = my_merge(n1->next,n2);
            return n1;
                
        }
        else
        {
            n2->next = my_merge(n1,n2->next);
            return n2;
        }
    }
};
