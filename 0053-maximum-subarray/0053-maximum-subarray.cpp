class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxans = INT_MIN;
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            
            sum += nums[i];
            maxans = max(maxans,sum);
            
            if(sum < 1)
            {
                sum = 0;
            }
            
        }
        
        return maxans;
        
    }
};