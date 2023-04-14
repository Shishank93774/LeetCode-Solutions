//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int tot = 0;
        for(int i = 0; i<n; i++) tot += (arr[i] <= k);
        int i = 0, cur = 0, ans = INT_MAX;
        int j = 0;
        while(i<n){
            while(j<n and j-i+1<=tot) cur += (arr[j++] <= k);
            ans = min(ans, tot - cur);
            cur -= (arr[i++] <= k);
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends