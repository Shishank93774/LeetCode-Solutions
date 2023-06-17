#define all(x) (x).begin(), (x).end()
#define getunique(x) {sort(all(x)); x.erase(unique(all(x)), x.end());}

const int N = 2e3+3;
int dp[N][N][2];
class Solution {
    int rec(int i, int j, bool where, vector<int> &a1, vector<int> &a2){
        if(i == a1.size()) return 0;
        
        int prev = INT_MIN;
        if(where){
            prev = a2[j];
        }else if(i>0){
            prev = a1[i-1];
        }
        j = upper_bound(a2.begin() + j, a2.end(), prev) - a2.begin();
        
        if(dp[i][j][where] != -1) return dp[i][j][where];
        int &ans = dp[i][j][where] = 1e9;
        
        if(j<a2.size()) ans = rec(i+1, j, true, a1, a2) + 1;
        if(prev < a1[i]) ans = min(ans, rec(i+1, j, false, a1, a2));
        
        return ans;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        getunique(arr2);
        memset(dp, -1, sizeof dp);
        int ans = rec(0, 0, false, arr1, arr2);
        return ans>=1e9?-1:ans;
    }
};