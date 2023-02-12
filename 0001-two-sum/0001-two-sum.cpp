class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n=nums.size();
        vector<pair<int,int>> ans(n);
        for(int i=0;i<nums.size();i++)
        {
            ans[i]={nums[i],i};
        }
        sort(ans.begin(),ans.end());
        int i=0,j=nums.size()-1;


        while(i<j)
        {
            if(ans[i].first + ans[j].first == target)
            {
                return {ans[i].second,ans[j].second};

            }
            else if(ans[i].first  + ans[j].first < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return {};
    }
};