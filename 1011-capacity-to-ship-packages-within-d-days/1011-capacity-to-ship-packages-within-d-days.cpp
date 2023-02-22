class Solution {
public:
    
    bool helper(vector<int> nums, int mid, int days)
    {
        
        int cnt = 1,sum = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            
            if(sum > mid)
            {
                cnt++;
                sum = nums[i];
            }
            
                
            
        }
        return cnt<=days;
        
    }
    
    int shipWithinDays(vector<int>& nums, int days) {
        
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        cout<<high<<endl;
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(helper(nums, mid, days))
            {
               
                high = mid - 1;
                
            }
            else
            {
                low = mid + 1;
            }
               
        }
        
        return low;
    }
};