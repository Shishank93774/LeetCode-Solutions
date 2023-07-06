//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int x) {
        // Your code goes here
        vector<vector<int> > ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0; i+3<n; i++){
            
            if(i>0 and arr[i]==arr[i-1]) continue;
            if(1ll*arr[i]+arr[i+1]+arr[i+2]+arr[i+3]>x) break;
            if(1ll*arr[i]+arr[n-3]+arr[n-2]+arr[n-1]<x) continue;
            
            for(int j = i+3; j<n; j++){
                
                if(j+1<n and arr[j]==arr[j+1]) continue;
                if(1ll*arr[i]+arr[i+1]+arr[i+2]+arr[j]>x) break;
                if(1ll*arr[i]+arr[j-2]+arr[j-1]+arr[j]<x) continue;
                
                int l = i+1, r = j-1;
                int tot = 1ll*arr[i] + arr[j];
                int req = 1ll*x - tot;
                
                while(l<r){
                    if(1ll*tot + arr[l] + arr[r] < x) l++;
                    else if(1ll*tot + arr[l] + arr[r] > x) r--;
                    else{
                        ans.push_back({arr[i], arr[l], arr[r], arr[j]});
                        l++; r--;
                        while(l<r and l<j and arr[l-1]==arr[l]) l++;
                        while(l<r and r>i and arr[r]==arr[r+1]) r--;
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends