/*
Question# + Difficulty + Topic + Company + Similar_Question
[203] [Remove Linked List Elements] [Easy] [Linked List  ] 
[] 
[27 237].cpp
*/


/* Recursive */
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        head->next = removeElements(head->next,val);
        return head->val==val? head->next:head;
        
    }
};


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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        while(head->val ==val&&head->next) head = head->next;
        if(head->val==val) return NULL;
        ListNode* tmp = head;
        while(head->next)
        {
            while(head->next->val==val)
            {
                head->next = head->next->next; 
                if(!head->next) return tmp;
            }
            head = head->next;
        }
        return tmp;
    }
};
