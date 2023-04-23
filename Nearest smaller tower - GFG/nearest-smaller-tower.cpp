//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n = arr.size();
        vector<int> pse(n), nse(n);
        stack<int> stk;
        for(int i = 0; i<n; i++){
            while(!stk.empty() and arr[stk.top()] >= arr[i]) stk.pop();
            if(stk.empty()) pse[i] = -1;
            else pse[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int> ();
        for(int i = n-1; i>=0; i--){
            while(!stk.empty() and arr[stk.top()] >= arr[i]) stk.pop();
            if(stk.empty()) nse[i] = n;
            else nse[i] = stk.top();
            stk.push(i);
        }
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            if(pse[i] == -1 and nse[i] == n){
                ans[i] = -1;
            }else if(pse[i] == -1){
                ans[i] = nse[i];
            }else if(nse[i] == n){
                ans[i] = pse[i];
            }else{
                if(nse[i] - i == i - pse[i]){
                    if(arr[pse[i]] <= arr[nse[i]]){
                        ans[i] = pse[i];
                    }else{
                        ans[i] = nse[i];
                    }
                }else if(nse[i] - i < i - pse[i]){
                    ans[i] = nse[i];
                }else{
                    ans[i] = pse[i];
                }
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
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends