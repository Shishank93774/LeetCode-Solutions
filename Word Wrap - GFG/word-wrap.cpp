//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

const int N = 2502 + 2;
int dp[N][N];
class Solution {
    int rec(int i, int j, int k, vector<int> &arr, int n){
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int &ans = dp[i][j];
        ans = 1e9;
        if(arr[i] <= (k-j)) ans = min(1ll*ans, 1ll*(k-arr[i]-j)*(k-arr[i]-j) + rec(i+1, 0, k, arr, n));
        if(arr[i]+1 <= (k-j)) ans = min(ans, rec(i+1, j+1+arr[i], k, arr, n));
        return ans;
    }
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        memset(dp, -1, sizeof dp);
        return rec(0, 0, k, nums, nums.size());
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends