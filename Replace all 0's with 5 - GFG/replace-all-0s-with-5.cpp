//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
// Driver program to test above function

// } Driver Code Ends
class Solution{
  public:
    /*you are required to complete this method*/
    int convertFive(int n)
    {
    //Your code here
    
        if(n==0)
            return 5;
            
            int ans=0, i=1;
            
        while(n)
        {
            int last = n%10;
            
            if(last == 0)
            {
                ans = ans + (i * 5);
            }
            else
            {
                ans = ans + (i * last);
            }
            n/=10;
            i*=10;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	Solution obj;
    	cout<<obj.convertFive(n)<<endl;
    }
}
// } Driver Code Ends