//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    
  private:
    
    int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        
        if(i<0 or j<0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j])
        {
            return 1 + helper(i-1, j-1, s1, s2, dp);
        }
        
        return dp[i][j] = max(helper(i, j-1, s1, s2, dp), helper(i-1, j, s1, s2, dp));
        
    }
    
  public:
    int longestPalinSubseq(string s1) {
        //code here
        string s2 = s1;
        int n = s1.size();
        int m = s2.size();
        reverse(s2.begin(), s2.end());
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return helper(n-1, m-1, s1, s2, dp);
        
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends