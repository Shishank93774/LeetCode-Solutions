//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string &s, string &t)
    {
        // code here
        int n = s.size(), m = t.size();
        vector<int> down(m+1, false), cur(m+1, false);
        down[m] = true;
        for(int i = n-1; i>=0; i--){
           if(s[i] == '*') cur[m] = down[m];
           for(int j = m-1; j>=0; j--){
              cur[j] = false;
              if(s[i] == t[j]) cur[j] = down[j+1];
              else{
                 if(s[i] == '?') cur[j] = down[j+1];
                 else if(s[i] == '*'){
                    for(int k = j; k<=m; k++){
                       cur[j] = cur[j] or down[k];
                       if(cur[j]) break;
                    }
                 }
              }
           }
           down = cur;
        }
        
        return down[0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends