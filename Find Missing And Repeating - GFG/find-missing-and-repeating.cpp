//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int i = 0;
        int d = -1;
        while(i<n){
            if(arr[i] == (i+1)){
                i++;
            }else if(arr[i] == arr[arr[i]-1]){
                d = arr[i];
                i++;
            }else{
                swap(arr[i], arr[arr[i]-1]);
            }
        }
        for(int i = 0; i<n; i++){
            if(arr[i] != i+1 and arr[i] == d) return {d, i+1};
        }
        return {-1, -1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends