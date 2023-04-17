//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string str)
{
    // your code here
    int n = str.size();
    if(n&1) return -1;
    stack<char> stk;
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(!stk.empty() and stk.top() == '{' and str[i] == '}') stk.pop();
        else{
            if(str[i] == '}') ans++;
            stk.push('{');
        }
    }
    ans += stk.size()/2;
    return ans;
}