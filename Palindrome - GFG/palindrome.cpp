//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    // Code here.
		    string ret="";   
		    int rev=0;
		    int m=n;
		    
		    while(n)
		    {
		        rev=rev*10 + (n%10);
		        n/=10;
		    }
		    
		    if(rev==m)
		    {
		        ret="Yes";
		    }
		    else
		    {
		        ret="No";
		    }
		    
		    return ret;
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends