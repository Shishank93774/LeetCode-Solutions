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
        set<vector<int> > ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0; i+3<n; i++){
            for(int j = 3; j<n; j++){
                int l = i+1, r = j-1;
                int tot = arr[i] + arr[j];
                int req = x - tot;
                while(l<r){
                    if(tot + arr[l] + arr[r] < x) l++;
                    else if(tot + arr[l] + arr[r] > x) r--;
                    else{
                        ans.insert({arr[i], arr[l], arr[r], arr[j]});
                        l++; r--;
                    }
                }
            }
        }
        return vector<vector<int> >(ans.begin(), ans.end());
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