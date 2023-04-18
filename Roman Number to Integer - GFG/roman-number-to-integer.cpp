//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

map<char, int> deg = {
    {'I', 0},
    {'V', 1},
    {'X', 2},
    {'L', 3},
    {'C', 4},
    {'D', 5},
    {'M', 6}
};

map<char, int> vals = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        int ans = 0, n = s.length();
        int pdeg = deg[s[n-1]];
        ans += vals[s[n-1]];
        int f = 1;
        for(int i = n-2; i>=0; i--){
            if(deg[s[i]] < pdeg) f = -1;
            else if(deg[s[i]] > pdeg) f = 1;
            else{}
            pdeg = deg[s[i]];
            ans += f*vals[s[i]];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends