const int N = 15;
int dp[N][(1<<N)][N];

class Solution {
    void genSol(int i, int last, int mask, int first, vector<int> &arr, vector<int> &sol){
        if(i == sol.size()) return;
        int mn = 1e9, v = -1;
        
        for(int b = 0; b<sol.size(); b++){
            if(mask&(1<<b)) continue;
            
            int a = dp[b][mask|(1<<b)][first] + abs(last - arr[b]);
            
            if(a< mn){
                mn = a;
                v = b;
            }
        }
        sol[i] = v;
        genSol(i+1, v, mask|(1<<v), first, arr, sol);
        
    }
public:
    vector<int> findPermutation(vector<int>& arr) {
        int n = arr.size();
        vector<int> sol(n);
        
        for(int i = 0; i<n; i++)
            for(int b = 0; b<(1<<n); b++)
                for(int j = 0; j<n; j++)
                    dp[i][b][j] = -1;
        
        
        auto rec = [&](int i, int last, int mask, int first, auto &&rec)->int{
            if(i == n) return abs(last - arr[first]);
            
            int &ans = dp[last][mask][first];
            if(ans != -1) return ans;
            
            ans = 1e9;
            
            for(int b = 0; b<n; b++){
                if(mask&(1<<b)) continue;
                int a = rec(i+1, b, mask|(1<<b), first, rec) + abs(last - arr[b]);
                
                if(a < ans){
                    sol[i] = b;
                }
                
                ans = min(ans, a);
            }
            return ans;
        };
        int ans = 1e9;
        int mn = 1e9, v = -1;
        for(int f = 0; f<n; f++){
            int a =  rec(1, f, 1<<f, f, rec);
            if(a < mn){
                mn = a;
                v = f;
            }
        }
        sol[0] = v;
        genSol(1, v, 1<<v, v, arr, sol);
        
        return sol;
    }
};