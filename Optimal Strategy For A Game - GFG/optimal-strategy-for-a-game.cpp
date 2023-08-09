//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
const int N = 1e3+3;
int dp[N][N][2];
class Solution{
    public:
    long long maximumAmount(int arr[], int n){
        // Your code here
        int sum = accumulate(arr, arr+n, 0ll);
        memset(dp, -1, sizeof dp);
    
        auto rec = [&](int l, int r, bool turn, auto &&rec)->int{
            if(l == r) {
                if(turn) return arr[l];
                return -1*arr[l];
            }
    
            if(dp[l][r][turn] != -1) return dp[l][r][turn];
    
            int a1 = 0, a2 = 0;
            if(turn){
                a1 = arr[l] + rec(l+1, r, !turn, rec);
                a2 = arr[r] + rec(l, r-1, !turn, rec);
                return dp[l][r][turn] = max(a1, a2);
            }else{
                a1 = -arr[l] + rec(l+1, r, !turn, rec);
                a2 = -arr[r] + rec(l, r-1, !turn, rec);
                return dp[l][r][turn] = min(a1, a2);
            }
        };
    
        int totA = (sum + rec(0, n-1, true, rec))/2;
        return totA;
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends