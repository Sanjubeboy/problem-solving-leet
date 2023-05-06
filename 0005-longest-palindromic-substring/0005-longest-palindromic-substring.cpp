class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        if(n==1)
            return s;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        int ans_i = INT_MIN;
        int ans_j = INT_MIN;
        
        
        
        for(int it=0; it<n; it++)
        {
            int i=0, j=it;
            while(i<n and j<n)
            {
                if(i == j)
                {
                    dp[i][j] = 1;
                    ans_i = i;
                    ans_j = j-i+1;
                }
                
                else if (i+1 == j)
                {
                    dp[i][j] = (s[i] == s[j]);
                    if(dp[i][j] == 1)
                    {
                        ans_i = i;
                        ans_j = j-i+1;
                    }
                }
                
                else
                {
                    dp[i][j] = (s[i]==s[j] and dp[i+1][j-1] == 1);
                    if(dp[i][j] == 1)
                    {
                        ans_i = i;
                        ans_j = j-i+1;
                    }
                }
                
                i++;
                j++;
            }
            
            
        }
        
        return s.substr(ans_i, ans_j);
        
        
    }
};