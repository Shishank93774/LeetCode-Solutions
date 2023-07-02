#define set_bits __builtin_popcount

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int m = requests.size();
        vector<int> poss(1<<m);
        iota(poss.begin(), poss.end(), 0);
        sort(poss.begin(), poss.end(), [&](int a, int b){
           return set_bits(a) > set_bits(b);
        });
        for(int pos = 0; pos < (1<<m); pos++){
            int mask = poss[pos];
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
            if(chk) return cnt;
        }
        return -1;
    }
};