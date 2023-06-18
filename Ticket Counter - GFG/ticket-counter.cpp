//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        int start = 1; 
        int end = N;
        
        int flag = 0;
        
        while(abs(start-end) > K)
        {
            if(flag == 0)
                start += K;
            else
                end -= K;
                
            flag = !flag;
        }
        
        if(flag) return start;
        return end;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends