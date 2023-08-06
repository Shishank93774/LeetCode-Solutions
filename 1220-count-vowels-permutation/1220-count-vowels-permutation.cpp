vector<int> nxtPos[5] = {{1},{0,2},{0,1,3,4},{2,4},{0}};
const int mod = 1e9+7;
class Solution {
public:
    int countVowelPermutation(int n) {
        
        vector<int> down(5, 0), cur(5);
        for(int p = 0; p<5; p++) down[p] = 1;
        
        for(int i = n-1; i>=1; i--){
            for(int p = 0; p<5; p++){
                int ans = 0;
                for(int nxt: nxtPos[p]){
                    ans += down[nxt];
                    ans %= mod;
                }
                cur[p] = ans;
            }
            down = cur;
        }
        int ans = 0;
        for(int p = 0; p<5; p++){
            ans += down[p];
            ans %= mod;
        }
        return ans;
    }
};