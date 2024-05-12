const int N = 15;
int dp[N][(1<<N)];

class Solution {
    void genSol(int i, int last, int mask, vector<int> &arr, vector<int> &sol){
        if(i == sol.size()) return;
        int mn = 1e9, v = -1;
        
        for(int b = 0; b<sol.size(); b++){
            if(mask&(1<<b)) continue;
            
            int a = dp[b][mask|(1<<b)] + abs(last - arr[b]);
            
            if(a< mn){
                mn = a;
                v = b;
            }
        }
        sol[i] = v;
        genSol(i+1, v, mask|(1<<v), arr, sol);
        
    }
public:
    vector<int> findPermutation(vector<int>& arr) {
        int n = arr.size();
        vector<int> sol(n);
        
        for(int i = 0; i<n; i++)
            for(int b = 0; b<(1<<n); b++)
                dp[i][b] = -1;
        
        
        auto rec = [&](int i, int last, int mask, auto &&rec)->int{
            if(i == n) return abs(last - arr[0]);
            
            int &ans = dp[last][mask];
            if(ans != -1) return ans;
            
            ans = 1e9;
            
            for(int b = 0; b<n; b++){
                if(mask&(1<<b)) continue;
                ans = min(ans, rec(i+1, b, mask|(1<<b), rec) + abs(last - arr[b]));
            }
            return ans;
        };
        rec(1, 0, 1, rec);
        sol[0] = 0;
        genSol(1, 0, 1, arr, sol);
        
        return sol;
    }
};