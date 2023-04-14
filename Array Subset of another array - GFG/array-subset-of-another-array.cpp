//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends

const int N = 1e6+6;

int cnt[N+1];
string isSubset(int a1[], int a2[], int n, int m) {
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i<n; i++) cnt[a1[i]]++;
    for(int i = 0; i<m; i++) cnt[a2[i]]--;
    for(int i = 0; i<N; i++) if(cnt[i] < 0) return "No";
    return "Yes";
    
}