//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int arr[], int n, int x) {

        // code here.
        long cur[x+1] = {};
        for(int i = n-1; i>=0; i--){
            for(int rem = 0; rem<=x; rem++){
                if(rem == 0) cur[rem] = 1;
                else{
                    cur[rem] = cur[rem];
                    if(arr[i] <= rem) cur[rem] += cur[rem-arr[i]];
                }
            }
        }
    
        return cur[x];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends