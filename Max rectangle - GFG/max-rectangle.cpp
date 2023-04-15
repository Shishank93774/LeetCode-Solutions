//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    int getMaxArea(vector<int> &arr, int n)
    {
        // Your code here
        vector<int> nse(n+1), pse(n+1);
        stack<int> stk;
        for(int i = 0; i<n; i++){
            while(!stk.empty() and arr[stk.top()] >= arr[i]) stk.pop();
            if(stk.empty()) pse[i] = -1;
            else pse[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for(int i = n-1; i>=0; i--){
            while(!stk.empty() and arr[stk.top()] > arr[i]) stk.pop();
            if(stk.empty()) nse[i] = n;
            else nse[i] = stk.top();
            stk.push(i);
        }
        int ans = arr[0];
        for(int i = 0; i<n; i++) ans = max(ans, arr[i]*(nse[i] - pse[i] - 1));
        return ans;
    }
  public:
    int maxArea(int arr[MAX][MAX], int n, int m) {
        // Your code here
        vector<int> hist(m);
        for(int j = 0; j<m; j++) hist[j] = arr[0][j];
        int ans = getMaxArea(hist, m);
        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++) hist[j] = (arr[i][j]==0?0:hist[j]+1);
            ans = max(ans, getMaxArea(hist, m));
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends