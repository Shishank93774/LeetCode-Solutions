int expo[32];
bool firstTime = true;
int dp[50][50][2];
class Solution {
    int K;
    int rec(int i, int jump, int back, bool canBack){
        if(i > K+1) return 0;
        
        int &ans = dp[jump][back][canBack];
        if(ans != -1) return ans;
        ans = (i==K);
        
        if(canBack) ans += rec(i-1, jump, back+1, false);
        ans += rec(i+expo[jump], jump+1, back, true);
        
        return ans;
    }
public:
    int waysToReachStair(int k) {
        K = k;
        if(firstTime){
            expo[0] = 1;
            for(int i = 1; i<32; i++)
                expo[i] = expo[i-1]<<1;
            firstTime = false;
        }
        for(int i = 0; i<50; i++)
            for(int j = 0; j<50; j++)
                dp[i][j][0] = dp[i][j][1] = -1;
        return rec(1, 0, 0, 1);
    }
};