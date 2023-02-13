class Solution {
public:
    int countOdds(int low, int high) {
        
        int cnt=0;
        
        if(low%2 == 0)
        {
            low++;
        }
        for(int i=low ;i<=high;i+=2)
        {
            cnt++;
        }
        return cnt;
    }
};