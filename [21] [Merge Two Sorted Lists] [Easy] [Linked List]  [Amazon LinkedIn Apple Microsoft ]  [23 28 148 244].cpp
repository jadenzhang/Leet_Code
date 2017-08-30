/*
Question# + Difficulty + Topic + Company + Similar_Question
[21] [Merge Two Sorted Lists] [Easy] [Linked List] 
[Amazon LinkedIn Apple Microsoft ] 
[23 28 148 244].cpp
*/

/* Iterative */
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        ListNode head(0);
        ListNode* tail = &head;
        ListNode* tmp1 = l1,*tmp2 = l2;
        while(tmp1&&tmp2)
        {
            if((tmp1->val)<(tmp2->val))
            {
                tail->next = tmp1;
                tmp1 = tmp1->next;
            }
            else
            {
                tail->next = tmp2;
                tmp2 = tmp2->next;
            }
            tail = tail->next;
        }
        tail->next =tmp1?tmp1:tmp2;
        return head.next;
    }
};

/* Recursive */

