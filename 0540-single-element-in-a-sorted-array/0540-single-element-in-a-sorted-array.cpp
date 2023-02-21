class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int low = 0, high = nums.size()-2;
        int ans;
        while(low<=high)
        {
            int mid = (low + high)/2;
            
            if(nums[mid] == nums[mid^1])
            {
                low = mid + 1;
            }
            else
            {
                // ans = nums[mid];
                high = mid - 1;
            }
            
        }
        
        return nums[low];
        
    }
};