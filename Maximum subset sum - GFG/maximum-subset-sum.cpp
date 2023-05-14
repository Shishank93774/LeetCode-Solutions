//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long findMaxSubsetSum(int n, vector<int> &arr) {
        // code here
        long long dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = arr[0];
        for(int i = 1; i<n; i++){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = arr[i] + max(dp[i-1][0], dp[i-1][1]);
        }
        // for(int i = 0; i<n; i++) cout<<dp[i][0]<<" "; cout<<"\n";
        // for(int i = 0; i<n; i++) cout<<dp[i][1]<<" ";
        return max(dp[n-1][0], dp[n-1][1]);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends