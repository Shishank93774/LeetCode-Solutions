//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string str) {
        int n = str.size();
        int cnt[26] = {0};
        bool mark[n] = {false};
        for(int i = 0; i<n; i++) cnt[str[i] - 'a']++;
        int l = 0, r = n - 1;
        bool dir = true;
        while(l<=r){
            if(dir){
                if(cnt[str[l] - 'a'] > 1){
                    cnt[str[l] - 'a']--;
                    mark[l] = true;
                    dir = !dir;
                }
                l++;
            }else{
                if(cnt[str[r] - 'a'] > 1){
                    cnt[str[r] - 'a']--;
                    mark[r] = true;
                    dir = !dir;
                }
                r--;
            }
        }
        string ans = "";
        for(int i = 0; i<n; i++) if(!mark[i]) ans += str[i];
        if(!dir) reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends