class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        
        vector<int> ret;
        vector<int> temp;
        
        while(k>0)
        {
            temp.push_back(k%10);
            k/=10;
        }
        
        reverse(begin(temp), end(temp));
        
        int u=num.size()-1;
        int v=temp.size()-1;
        int carry=0;
        
        while(u>=0 or v>=0)
        {
            int sum=carry;
            
            if(u>=0)
            {
                sum += num[u];
                u--;
            }
            if(v>=0)
            {
                sum+=temp[v];
                v--;
            }
            
            ret.push_back(sum%10);
            carry=sum/10;
        }
        
        if(carry)
        {
            ret.push_back(carry);
        }
        reverse(begin(ret), end(ret));
        return ret;
        
    }
};