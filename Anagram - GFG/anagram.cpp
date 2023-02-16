//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#include<string.h>
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        // Your code here
        
        unordered_map<char,int> mp;
        
        for(int i=0;a[i]!='\0';i++)
        {
            mp[a[i]]++;
        }
        int flag=0;
        for(int i=0;b[i]!='\0';i++)
        {
            if(mp.find(b[i]) != mp.end()   and  mp[b[i]]>0)
            {
                mp[b[i]]--;
            }
            
            else
            {
                flag=1;
                break;
            }
        }
        
        if(flag==0)
        {
            
            return true;
            
        }
        else 
        {
            return false;
        }
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends