class Solution {
public:
    
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> ans;
        int cnt = 0;
        
        pair<int,int> t = {intervals[0][0],intervals[0][1]};
        
        for(auto it: intervals)
        {
            cnt++;
            if(it[0] <= t.second)
            {
                t.second = max(t.second,it[1]);
            }
            
            else
            {
                ans.push_back({t.first,t.second});
                t.first = it[0];
                t.second = it[1];
            }
            
            if(cnt == intervals.size())
                ans.push_back({t.first,t.second});
            
            
        }
        
        return ans;
    }
};