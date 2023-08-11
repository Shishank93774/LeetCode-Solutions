//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string str) {
        // code here
        stack<int> stk;
        stk.push(-1);
        int ans = 0, n = str.size();
        for(int i = 0; i<n; i++){
            if(str[i] == '(') stk.push(i);
            else{
                stk.pop();
                if(stk.empty()) stk.push(i);
                else{
                    ans = max(ans, i - stk.top());
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends