/*
Question# + Difficulty + Topic + Company + Similar_Question
[2] [Add Two Numbers] [Medium] [Linked List Math ] 
[Amazon Microsoft Bloomberg Airbnb Adobe ] 
[43 67 371 415 445].cpp
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        bool carry = 0;
        ListNode *cur = new ListNode(0);
        ListNode *head = cur;
        while(l1||l2||carry)
        {
            int sum = 0;
            if(l1){sum+=l1->val;l1 = l1->next;}
            if(l2){sum+=l2->val;l2 = l2->next;}
            if(carry){sum++;carry = 0;}
            if(sum>=10){sum-=10;carry=1;}
            ListNode *tmp = new ListNode(sum);
            cur->next = tmp;
            cur = tmp;
        }
        return head->next;
        
    }
};
