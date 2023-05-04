class Solution {
public:
    
    int helper(int ind, int tar, vector<int> &coins, vector<vector<int>> &dp)
    {
        
        if(ind == 0)
        {
            // if(tar == 0)
            //     return 0;
            
            if( tar%coins[ind] == 0)
                return tar/coins[0];
            
            return 1e9;
        }
        
        if(dp[ind][tar] != -1)
            return dp[ind][tar];
        
        int take = 1e9;
        
        if(coins[ind] <= tar)
            take = 1 + helper(ind, tar-coins[ind], coins, dp);
        
        int ntake = helper(ind-1, tar, coins, dp);
        
        return dp[ind][tar] = min(take, ntake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans = helper(n-1, amount, coins, dp);
        if(amount == 0)
            return 0;
        
        if(ans == 1e9)
            return -1;
        
        return ans;
        
    }
};