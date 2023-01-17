class Solution {
public:
    int minFlipsMonoIncr(string str) {
        int n = str.size();
        int pre[n+1][2];
        pre[0][0] = pre[0][1] = 0;
        int cnt0 = 0, cnt1 = 0;
        for(int i = 0; i<n; i++){
            pre[i+1][0] = pre[i][0];
            pre[i+1][1] = pre[i][1];
            if(str[i] == '0') pre[i+1][0]++;
            else pre[i+1][1]++;
        }
        str += "$";
        int ans = n;
        for(int i = 0; i<=n; i++){
            int oneToLeft = pre[i][1], zeroToRight = pre[n][0] - pre[i][0];
            int flipsReq = oneToLeft + zeroToRight + (str[i] == '0');
            ans = min(ans, flipsReq);
        }
        return ans;
    }
};