//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int x)
    {
        //Your Code Here
        sort(arr, arr+n);
        for(int l = 0; l+2<n; l++){
            for(int r = n-1; r-2 >=0; r--){
                int left = x - arr[l] - arr[r];
                int lo = l+1, hi = r-1;
                while(lo <= hi){
                    int mid = lo + (hi - lo)/2;
                    if(arr[mid] < left){
                        lo = mid + 1;
                    }else if(arr[mid] > left){
                        hi = mid - 1;
                    }else return true;
                }
            }
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends