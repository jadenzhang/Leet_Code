/*
Question# + Difficulty + Topic + Company + Similar_Question
[23] [Merge k Sorted Lists] [Hard] [Linked List Divide and Conquer Heap ] 
[Google Facebook Microsoft Amazon Uber LinkedIn Twitter Airbnb IXL ] 
[21 264].cpp
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
    struct comp
    {
        bool operator()(ListNode* a, ListNode* b){return a->val> b->val;}
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp> heap;
        //push all list head to heap
        for(int i = 0;i<lists.size();i++) {if(lists[i]) heap.push(lists[i]);}
        if(heap.empty()) return nullptr;
        //set up result list
        ListNode* head = heap.top();
        heap.pop();
        if(head->next) heap.push(head->next);// push back next element of poped list
        ListNode* tail = head;
        
        while(!heap.empty())
        {
            tail->next = heap.top();
            heap.pop();
            tail = tail->next;
            if(tail->next) heap.push(tail->next);// push back next element of poped list
        }
        return head;
        
        
    }
};
