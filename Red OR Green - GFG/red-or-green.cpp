//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
       int RedOrGreen(int n,string s) {
           //code here
           
           int red=0;
           int green=0;
           
         for(int i=0; i<n; i++)
         {
             if(s[i] == 'R')
                red++;
            else
                green++;
         }
         
         return min(red,green);
           
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        string S;
        cin >> S;
        Solution ob;
        cout << ob.RedOrGreen(N,S) << endl;
    }
    return 0;
}
// } Driver Code Ends