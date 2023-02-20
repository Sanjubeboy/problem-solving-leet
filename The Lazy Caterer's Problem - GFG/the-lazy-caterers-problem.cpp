//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
   	int maximum_Cuts(int n){
   	    // Code here
   	    
   	    //2  4 7 11
   	    
   	    if(n==1)
   	        return 2;
   	    int i = 2,ans = 2;
   	    n--;
   	    
   	    while(n--)
   	    {
   	        ans = ans + i;
   	        i++;
   	    }
   	    
   	    return ans;
   	    
   	}    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.maximum_Cuts(n);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends