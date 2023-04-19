//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here
        int sz = unordered_set<char>(str.begin(), str.end()).size();
        int i = 0, j = 0, n = str.size();
        int ans = n, tmp = 0;
        unordered_map<char, int> mp;
        while(i<n){
            while(j<n and mp.size() != sz) tmp++, mp[str[j++]]++;
            if(ans > tmp and mp.size() == sz) ans = tmp;
            mp[str[i]]--;
            if(mp[str[i]] == 0) mp.erase(str[i]);
            i++, tmp--;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends