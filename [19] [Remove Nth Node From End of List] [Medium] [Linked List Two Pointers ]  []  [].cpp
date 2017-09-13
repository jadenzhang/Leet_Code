/*
Question# + Difficulty + Topic + Company + Similar_Question
[19] [Remove Nth Node From End of List] [Medium] [Linked List Two Pointers ] 
[] 
[].cpp
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        ListNode* head1 = head;
        while(n)
        {
            tmp = tmp->next;
            n--;
        }
        if(!tmp) return head->next;//Delete the head itself, because tmp=0 means delete head
        while(tmp->next)
        {
            head1 = head1->next;
            tmp = tmp->next;
        }
        head1->next = head1->next->next;
        
        return head;
    }
};
