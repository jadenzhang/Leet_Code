/*
Question# + Difficulty + Topic + Company + Similar_Question
[141] [Linked List Cycle] [Easy] [Linked List Two Pointers ] 
[Amazon Microsoft Bloomberg Yahoo ] 
[142].cpp
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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* fast  = head;
        ListNode* slow = head;
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) return true;
        }
        return false;
        
    }
};
