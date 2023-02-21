//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string reverseString(string s);
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	    {
	        string s;
	        getline(cin,s);
	        cout<<reverseString(s)<<endl;
	    }
}

// } Driver Code Ends


string reverseString(string s)
{
    //code here.
    string ans ="";
    
    int hash[26]={0};
    
    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i] == ' ')
            continue;
        
        if(hash[s[i] - 'A'] == 0)
        {
            ans += s[i];
            hash[s[i] - 'A'] = 1;
        }
        
        
    }
    return ans;
    
}