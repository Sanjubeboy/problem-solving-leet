class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        
        vector<int> ans(rowIndex+1);
        
        
        ans[0] = 1;
        ans[rowIndex] = 1;
        long long res = 1, n=rowIndex;
        
        for(int i=1; i<rowIndex; i++)
        {
            
            res *= n-i+1;
            res /= i;
            
            ans[i] = res;
            
        }
        
        return ans;
        
    }
};