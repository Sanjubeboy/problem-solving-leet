class Solution {
public:
    
    
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        
        while(left <= mid and right <= high)
        {
            
            if(nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            
            
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
            
        }
        
        while(left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }
        
        while(right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }
        
        
        for(int i = low; i<= high; i++)
        {
            nums[i] = temp[i - low];
        }
        
    }
    
    void helper(vector<int> &nums, int low, int high)
    {
        
        if(low == high)
            return;
        
        int mid = (low + high) / 2;
        
        helper(nums, low,mid);
        helper(nums, mid+1, high);
        
        merge(nums, low, mid, high);
        
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
        
        
        int low = 0;
        int high = nums.size()-1;
        
        helper(nums,low,high);
        
        return nums;      
    }
};