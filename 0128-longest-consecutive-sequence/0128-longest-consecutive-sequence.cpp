class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st;
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            st.insert(nums[i]);
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(st.find(nums[i] - 1)  != st.end())
            {
                continue;
            }
            
            int n = nums[i];
            int cnt = 0;
            
            while(st.count(n) >= 1)
            {
                cnt++;
                n++;
            }
            
            ans = max(ans,cnt);
            
        }
        
        return ans;
        
    }
};