//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    string reverse(string s)
    { 
        //code here.
        
        int i=0,j=s.size()-1;
        
        while(i<=j)
        {
            
            if(isalpha(s[i])  and isalpha(s[j]))
            {
                swap(s[i],s[j]);
                i++;
                j--;
                
            }
            
            while(!isalpha(s[i]))
            {
                i++;
            }
            
            while(!isalpha(s[j]))
            {
                j--;
            }
            
            
        }
        
        return s;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.reverse(s) << endl;
    }
return 0;
}


// } Driver Code Ends