//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    string rec(int i, string &str, int n){
        if(i == n) return "";
        if(str[i-1] == str[i]) return rec(i+1, str, n);
        return str[i-1] + rec(i+1, str, n);
    }
    public:
    string removeConsecutiveCharacter(string str)
    {
        // code here.
        str += "$";
        if(str.size() == 1) return str;
        return rec(1, str, str.size());
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends