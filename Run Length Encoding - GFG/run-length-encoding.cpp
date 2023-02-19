//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string s)
{     
  //Your code here 
  
  string ans = "";
  
  if(s.size() == 1)
  {
      ans += s;
      ans += '1';
      return ans;
  }
  
  
  int cnt = 1;
  
  for(int i=1; i<s.size(); i++)
  {
      
      if(s[i] == s[i-1])
      {
          cnt++;
          
      }
      
      else
      {
          ans += s[i-1];
          ans += cnt + '0';
          cnt=1;
      }
      
      if(i == s.size()-1)
      {
          ans += s[i];
          ans += cnt+'0';
      }
      
      
      
  }
  
  return ans;
}     
 
