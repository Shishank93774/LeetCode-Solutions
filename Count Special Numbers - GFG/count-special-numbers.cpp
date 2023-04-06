//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> arr) {
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++) mp[arr[i]]++;
        if(mp[1] == 1) return n-1;
        else if(mp[1] > 1) return n;
        int ans = 0;
        for(int i = 0; i<n; i++){
            int x = arr[i];
            if(mp[x] > 1) {
                ans++; continue;
            }
            for(int j = 2; j*j<=x; j++){
                if(x == j){
                    ans += (mp[x] > 1);
                    break;
                }else if(x%j == 0 and (mp.count(j) or mp.count(x/j))){
                    ans++; break;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends