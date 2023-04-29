//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &iv,int k){
        // Code here
        map<int, int> cnt;
        for(int i = 0; i<n; i++) cnt[iv[i][0]]++, cnt[iv[i][1] + 1]--;
        int sum = 0, ans = -1, mx = -1, prev = -1;
        for(auto it: cnt){
            if(it.second <= 0){
                if(k <= sum){
                    mx = sum;
                    ans = max(ans, it.first - 1);
                }
                sum += it.second;
            }else{
                sum += it.second;
                if(k <= sum){
                    mx = sum;
                    ans = max(ans, it.first);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends