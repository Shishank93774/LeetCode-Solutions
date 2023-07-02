class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        int ans = 0;
        for(int mask = 0; mask<(1<<m); mask++){
            vector<int> deg(n, 0);
            int cnt = 0;
            for(int i = 0; i<m; i++){
                if(mask&(1<<i)){
                    deg[requests[i][0]]--;
                    deg[requests[i][1]]++;
                    cnt++;
                }
            }
            bool chk = true;
            for(int i = 0; i<n; i++) if(deg[i] != 0) {chk = false; break;}
            if(chk) ans = max(ans, cnt);
        }
        return ans;
    }
};