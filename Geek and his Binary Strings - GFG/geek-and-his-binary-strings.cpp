//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    const int mod = 1e9+7;
	public:
	int prefixStrings(int n)
	{
	    // Your code goes here
        vector<int> down(2*n+1, 0), cur(2*n+1);
        down[0] = 1;
	    for(int i = 2*n-1; i>=0; i--){
	        for(int sum = n; sum >= 0; sum--){
	            int ans = 0;
	            if(sum != n) ans = down[sum+1];
	            if(sum) ans += down[sum-1];
	            ans %= mod;
	            
	            cur[sum] = ans;
	        }
	        down = cur;
	    }
	    
	    return down[0];
	    
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

       

        Solution ob;
        cout << ob.prefixStrings(n);
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends