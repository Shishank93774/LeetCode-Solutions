//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<pair<int, int> > res;
        for(int i = 0; i<n; i++) res.push_back({arr[i], i});
        sort(res.begin(), res.end());
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++) mp[res[i].second] = i;
        vector<long long> tmp;
        int bg = res[0].first;
        long long sum = res[0].first;
        tmp.push_back(0);
        for(int i = 1; i<n; i++){
            if(bg < res[i].first){
                bg = res[i].first;
                tmp.push_back(sum);
            }else{
                tmp.push_back(tmp.back());
            }
            sum += res[i].first;
        }
        vector<long long> ans(n);
        for(int i = 0; i<n; i++) ans[i] = tmp[mp[i]];
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends