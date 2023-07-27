//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> wordBreak(int n, vector<string>& dict, string x)
    {
        // code here
        vector<string> ans;
        int len = x.size();
        auto dfs = [&](int i, string till, auto &&dfs)->void{
            if(i == len){
                ans.push_back(till);
                return;
            }
            
            for(string s: dict){
                if(i + s.size() <= len){
                    if(x.substr(i, s.size()) == s){
                        dfs(i+s.size(), (till.size()?(till + " " + s):s), dfs);
                    }
                }
            }
        };
        
        dfs(0, "", dfs);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends