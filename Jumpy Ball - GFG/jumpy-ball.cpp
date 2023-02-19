//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long jumpyBall(long long n)
    {
        // Write Your Code here
        long long ans = 0;
        
        while(n)
        {
            ans += n*2;
            n/=2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        long long ans  = ob.jumpyBall(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends