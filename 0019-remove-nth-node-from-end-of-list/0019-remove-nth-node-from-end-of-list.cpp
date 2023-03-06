/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* t1 = dummy;
        ListNode* t2 = dummy;
        
        while(n--)
        {
            t1 = t1->next;
        }
        
        while(t1->next)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        
        t2->next = t2->next->next;
        // delete(t2);
        
        return dummy->next;
        
    }
};