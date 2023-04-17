//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

const int N = 1111;
int dp[N];
class Solution
{
    bool rec(int i, const string &str, int n, vector<string> &dict){
        if(i == str.size()) return true;
        if(dp[i] != -1) return dp[i];
        int &ans = dp[i] = false;
        for(string &s: dict){
            if(s.size() <= (n-i) and str.substr(i, s.size()) == s){
                ans = (ans | rec(i+s.size(), str, n, dict));
                if(ans) return true;
            }
        }
        return false;
    }
public:
    int wordBreak(string str, vector<string> &dict) {
        //code here
        memset(dp, -1, sizeof dp);
        return rec(0, str, str.size(), dict);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends