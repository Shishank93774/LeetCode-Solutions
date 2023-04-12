//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int n){
        // code here
        list<int> lst;
        lst.push_back(1);
        for(int i = 2; i<=n; i++){
            int c = 0;
            auto j = prev(lst.end());
            while(j != prev(lst.begin())){
                int t = *j;
                t = t*i  + c;
                c = t/10;
                t = t%10;
                *j = t;
                j = prev(j);
            }
            while(c){
                lst.push_front(c%10);
                c /= 10;
            }
        }
        vector<int> ans(lst.begin(), lst.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends