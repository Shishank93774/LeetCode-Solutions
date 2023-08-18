//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<vector<int> > adj(k);
        vector<int> indeg(k, 0);
        
        for(int i = 1; i<n; i++){
            for(int j = 0; j<min(dict[i-1].size(), dict[i].size()); j++){
                int u = dict[i-1][j] - 'a';
                int v = dict[i][j] - 'a';
                if(u != v){
                    adj[u].push_back(v);
                    indeg[v]++;
                    break;
                }
            }
        }
        vector<bool> vis(k, false);
        string order;
        auto dfs = [&](int src, auto &&dfs)->void{
            order.push_back('a' + src);
            vis[src] = true;
            for(int nbr: adj[src]){
                indeg[nbr]--;
                if(indeg[nbr] == 0) dfs(nbr, dfs);
            }
        };
        for(int i = 0; i<k; i++){
            if(!vis[i] and indeg[i] == 0)
                dfs(i, dfs);
        }
        return order;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends