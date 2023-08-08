//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int dp[n+1], ans[n+1];
	    dp[0] = ans[0] = 0;
	    dp[1] = ans[1] = arr[0];
	    for(int i = 2; i<=n; i++){
	        int x = arr[i-1];
	        ans[i] = ans[i-1];
	        dp[i] = x;
	        for(int j = i-1; j>0; j--){
	            int y = arr[j-1];
	            if(y < x){
	                ans[i] = max(ans[i], dp[j] + x);
	                dp[i] = max(dp[i], dp[j] + x); 
	            }
	        }
	    }
	    return ans[n];
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends