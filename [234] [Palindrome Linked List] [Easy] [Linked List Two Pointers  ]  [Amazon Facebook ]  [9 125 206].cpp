/*
Question# + Difficulty + Topic + Company + Similar_Question
[234] [Palindrome Linked List] [Easy] [Linked List Two Pointers  ] 
[Amazon Facebook ] 
[9 125 206].cpp
*/

/* recursive but O(N) space */
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
    bool isPalindrome(ListNode* head) {
        return check(head, head);
    }
    
    bool check(ListNode*& head, ListNode* p) {
        if(!p) { return true; }
        bool isPal = check(head, p->next);
        if(head->val != p->val) {
            return false;
        }
        head = head->next;
        return isPal;
    }
};

/* O(1) Space need to find mid and reverse half of list*/
class Solution {
public:
    bool isPalindrome(ListNode *head) {
		if (!head || !head->next)
			return true;
		ListNode *slow = head, *fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = slow->next;
		slow->next = NULL;
		ListNode *second = reverseList(fast);
		while (second && second->val == head->val) {
			second = second->next;
			head = head->next;
		}
		slow->next = reverseList(fast);
    return second == NULL;
    }
private:
    ListNode *reverseList(ListNode *head) {
		ListNode *pre = NULL, *next = NULL;
		while (head) {
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
};
