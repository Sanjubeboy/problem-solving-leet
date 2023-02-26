class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        
        int ind1=-1,ind2;
        
        int n = nums.size();
        
        for(int i=n-2; i>=0; i--)
        {
            
            if(nums[i] < nums[i+1])
            {
                ind1 = i;
                break;
            }
            
        }
        
        cout<<ind1;
        
        if(ind1 == -1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        
        
        for(int i=n-1; i>=0; i--)
        {
            if(nums[i] > nums[ind1])
            {
                ind2 = i;
                break;
            }
        }
        
        
        swap(nums[ind1],nums[ind2]);
        
        int l = ind1+1;
        int h = n-1;
        
        while(l<=h)
        {
            swap(nums[l],nums[h]);
            
            l++;
            h--;
            
        }
        
        
    }
};