const int N = 1001;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n, 1);
        vector<int> par(n, -1);
        vector<int> ans;
        
        int mx = 0;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(arr[i]%arr[j] == 0 and dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    par[i] = j;
                }
            }
            if(dp[i] > dp[mx]) mx = i;
        }
        
        while(mx >= 0){
            ans.push_back(arr[mx]);
            mx = par[mx];
        }
        
        return ans;        
    }
};