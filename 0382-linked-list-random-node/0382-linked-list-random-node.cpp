class Solution {
public:
    vector<int>list;
    Solution(ListNode* head)
     {
        ListNode * tmp = head;
        while(tmp)
        {
            list.push_back(tmp->val);
            tmp = tmp->next;
        }
    } 
    int getRandom() 
    {
        int n = list.size();
        int ind = rand()%n;
        return list[ind];
    }
};