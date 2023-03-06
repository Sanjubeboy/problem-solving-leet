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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* dummy = new ListNode(-1);
        
        ListNode* ptr = dummy;
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        
        while(t1 and t2)
        {
            if(t1->val <= t2->val)
            {
                ptr->next = t1;
                ptr = ptr->next;
                t1 = t1->next;
            }
            
            else
            {
                ptr->next = t2;
                ptr=ptr->next;
                t2 = t2->next;
            }
        }
        
        if(!t1)
            ptr->next = t2;
        else
            ptr->next = t1;
        
        return dummy->next;
        
    }
};