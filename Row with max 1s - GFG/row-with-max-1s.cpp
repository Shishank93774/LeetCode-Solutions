//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > &arr, int n, int m) {
	    // code here
	    int mx = 0, mxR = -1;
	    auto cnt1 = [&](vector<int> &arr){
	        int l = 0, r = m-1;
	        int ans = m;
	        while(l<=r){
	            int mid = l + (r - l)/2;
	            if(arr[mid] == 1){
	                r = mid - 1;
	                ans = mid;
	            }else{
	                l = mid + 1;
	            }
	        }
	        return ans;
	    };
	    
	    for(int i = 0; i<n; i++){
	        int cnt = cnt1(arr[i]);
	        if(m-cnt > mx){
	            mx = m - cnt;
	            mxR = i;
	        }
	    }
	    return mxR;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends