class Solution {
public:
    
    
    bool helper(int ind, int tar, vector<int> &nums, vector<vector<int>> &dp)
    {
        
        if(ind == 0)
            return tar == nums[ind];
        
        if(dp[ind][tar] != -1)
            return dp[ind][tar];
        
        bool take = false;
        if(nums[ind] <= tar)
            take = helper(ind-1, tar-nums[ind], nums, dp);
        
        bool ntake = helper(ind-1, tar, nums, dp);
        
        return dp[ind][tar] = take or ntake;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        int n = nums.size();
        
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
        }
        
        if(sum%2  or sum <0)
            return false;
        
        int target = sum/2;
        
        // vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        
        // return helper(n-1, target, nums, dp);
        
        
        //tabulation
        
        vector<int> dp(target+1, 0), cur(target+1, 0);
        
        
        for(int tar=0; tar<=target; tar++)
        {
            dp[tar] = (nums[0] == tar);
        }
        
        
        for(int ind = 1; ind<n; ind++)
        {
            for(int tar=0; tar<=target; tar++)
            {
                bool take = false;
                if(nums[ind] <= tar)
                    take = dp[tar-nums[ind]];
                
                bool ntake = dp[tar];
                
                cur[tar] = take or ntake;
            }
            dp = cur;
        }
        
        return dp[target];
    }
};