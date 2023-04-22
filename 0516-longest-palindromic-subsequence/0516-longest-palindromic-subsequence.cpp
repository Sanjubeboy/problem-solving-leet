class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        string t = s;
        reverse(t.begin(), t.end());
        
        int n = s.size();
        int m = t.size();
        
        
        // vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        vector<int> dp(m+1, 0);
        
        for(int i=1; i<=n; i++)
        {
            vector<int> cur(m+1, 0);
            for(int j=1; j<=m; j++)
            {
                
                if(s[i-1] == t[j-1])
                    cur[j] = 1 + dp[j-1];
                else
                    cur[j] = max(cur[j-1], dp[j]);
                
            }
            dp = cur;
        }
        
        return dp[m];
    }
};