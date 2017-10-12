/*
Question# + Difficulty + Topic + Company + Similar_Question
[160] [Intersection of Two Linked Lists] [Easy] [Linked List ] 
[Microsoft Amazon Bloomberg Airbnb ] 
[599].cpp
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur1 = headA, *cur2 = headB;
        while(cur1 != cur2){
            cur1 = cur1?cur1->next:headB;
            cur2 = cur2?cur2->next:headA;
        }
        return cur1;        
    }
};
