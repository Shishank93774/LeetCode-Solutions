int dp[1001], n, i, j, curAge, curScore, ans;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int> > arr;
        n = scores.size();
        dp[0] = 0;
        ans = 0;
        for(int i = 0; i<n; i++) arr.push_back({scores[i], ages[i]});
        
        sort(arr.begin(), arr.end(), [](const pair<int, int> &p1, const pair<int, int> &p2){
            return p1.second == p2.second?p1.first<p2.first:p1.second<p2.second;
        }); // Sort by ages.. toh takleef only on the lefts.  
        
        for(i = 1; i<=n; i++){
            curScore = arr[i-1].first, curAge = arr[i-1].second;
            dp[i] = 0;
            for(j = i-2; j>=0; j--) if(arr[j].first <= arr[i-1].first) dp[i] = max(dp[i], dp[j+1]);
            dp[i] += curScore;
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};