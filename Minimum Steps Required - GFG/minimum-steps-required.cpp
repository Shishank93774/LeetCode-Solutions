//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    int cnta = 0, cntb = 0, i = 0, n = str.length();
    while(i<n){
        int j = i + 1;
        while(j<n and str[j] == str[i]) j++;
        str[i] == 'a'? cnta++: cntb++;
        i = j;
    }
    return min(cnta, cntb) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends