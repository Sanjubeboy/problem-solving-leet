//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<int> findElements(int a[], int n)
    {
        // Your code goes here   
        vector<int> ans;
        int maxi = INT_MIN;
        int smax = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            if(a[i] >= maxi)
            {
                smax = maxi;
                maxi = a[i];
            }
            
            else
            {
                if(smax < a[i])
                {
                    smax = a[i];
                }
            }
        } 
        
        // cout<<maxi<<endl<<smax<<endl;
        
        for(int i=0; i<n; i++)
        {
            if(a[i] != smax and a[i]!= maxi)
            {
                ans.push_back(a[i]);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        Solution ob;
        vector <int> res = ob.findElements(a,n);
        
        for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
        cout<<endl;
    }
}
// } Driver Code Ends