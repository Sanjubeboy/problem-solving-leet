class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size()-1;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target) return true;
            
            //edge case [1,0, 1, 1, 1]
            if(nums[low] == nums[mid] and nums[mid] == nums[high]){
                low ++;
                high --;
                continue;
            }
            
            //left sorted
            
            if(nums[low] <= nums[mid]){
                if(target >= nums[low] and target <= nums[mid]){
                    high = mid -1;

                }
                else low = mid + 1;
            }
            
            //right sorted
            else{
                if(target >= nums[mid] and target <= nums[high]){
                    low = mid + 1;
                }
                else high = mid - 1;
            }
            
            
        }
        return false;
    }
};