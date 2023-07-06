//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    long long ans = 0;
	    sort(arr, arr+n);
	    for(int i = 0; i+2<n; i++){
	        for(int j = n-1; i+1<j; j--){
	            long long rem = sum - arr[i] - arr[j];
	            int l = i+1, r = j-1;
	            while(l<=r){
	                int mid = l + (r - l)/2;
	                if(arr[mid] < rem) l = mid+1;
	                else r = mid - 1;
	            }
	            ans += (l-1-i);
	        }
	    }
	    return ans;
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
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends