//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        // Your code goes here
        sort(arr, arr+n);
        int l = 0, r = accumulate(arr, arr+n, 0);
        
        auto chk = [&](int x){
            int sum = 0;
            int i = n-2;
            while(i>=0){
                if(arr[i+1] - arr[i] < k){
                    sum += arr[i+1] + arr[i];
                    i -= 2;
                }else{
                    i--;
                }
            }
            return (sum >= x);
        };
        
        while(l<=r){
            int mid = l + (r - l)/2;
            if(chk(mid))
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return l-1;
        
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends