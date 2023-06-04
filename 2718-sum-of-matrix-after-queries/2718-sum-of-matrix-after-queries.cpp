class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<bool> visR(n, false), visC(n, false);
        long long ans = 0;
        int remR = n, remC = n;
        auto it = prev(queries.end());
        for(;; it = prev(it)){
            auto q = *it;
            int t = q[0], idx = q[1], val = q[2];
            if(t == 0){ // Row
                if(!visR[idx]){
                    ans = ans + remC*val;
                    visR[idx] = true;
                    remR--;
                }
            }else{  // Col
                if(!visC[idx]){                    
                    ans = ans + remR*val;
                    visC[idx] = true;
                    remC--;
                }
            }
            if(it == queries.begin()) break;
        }
        return ans;
    }
};