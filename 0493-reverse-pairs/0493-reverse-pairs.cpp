class Solution {
public:
    
    
    int merge(vector<int> &nums, int low, int mid, int high)
    {
        
        int cnt = 0;
        
        int left = low;
        int right = mid+1;
        vector<int> temp;
        int j= mid+1;
        
        for(int i=low; i<=mid; i++)
        {
            while(j<=high and nums[i] > (2 * (long)nums[j]))
            {
                j++;
            }
            
            cnt += (j-(mid+1));
        }
        
        
        while(left<= mid && right <= high)
        {
            if(nums[right] < nums[left])
            {
                temp.push_back(nums[right]);
                
                right++;
            }
            
            else
            {
                temp.push_back(nums[left]);
                left++;
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
        
        for(int i=low; i<=high ;i++)
        {
            nums[i] = temp[i-low];
        }
        
        return cnt;
        
    }
    
    int merge_sort(vector<int> &nums, int low, int high)
    {
        
        if(low >= high)
            return 0;
        
        int mid = (low + high) / 2;
        int pairs = 0;
            
            
        pairs += merge_sort(nums, low, mid);
        pairs += merge_sort(nums, mid + 1, high);
        
        
        
//         while(left<= mid &&  right<=high)
//         {
            
//             if(nums[left] > 2*nums[right])
//             {
//                 right++;
//             }
//             else
//             {
//                 pairs += right - mid+1;
//                 left++;
//             }
            
//         }
        
        pairs += merge(nums, low, mid, high);
        
        return pairs;
        
    }
    
    int reversePairs(vector<int>& nums) {
        
        int low = 0;
        int high = nums.size()-1;
        
        
        int t = merge_sort(nums, low, high);
        
        for(auto it: nums)
        {
            cout<<it<<" "<<endl;
        }
        return t;
    }
};