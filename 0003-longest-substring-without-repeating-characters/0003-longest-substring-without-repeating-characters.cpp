class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // if(s.size() == 0)
            // return -1;
        
        unordered_map<char,int> mp;
        
        int l = 0;
        int ans = 0;
        
        for(int r=0; r<s.size(); r++)
        {
            
            if(mp.find(s[r]) != mp.end()  and  (mp[s[r]]>=l and mp[s[r]] <=r))
            {
                
                l = mp[s[r]] + 1;
                ans = max(ans,r-l+1);
                mp[s[r]] = r;
                
            }
            
            
            else
            {
                
                mp[s[r]] = r;
                
                ans = max(ans,r-l+1);
                
            }            
        }
        
        return ans;
        
    }
};