map<vector<int>, int > dp;
class Solution {
    
    int rec(int i, vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        if(dp.find(needs) != dp.end()) return dp[needs];
        if(i == special.size()){
            int req = 0;
            for(int p = 0; p<needs.size(); p++){
                req += needs[p]*price[p];
            }
            return req;
        }
        int ans = rec(i+1, price, special, needs);
        for(int s = 0; s<special.size(); s++){
            bool chk = true;
            for(int p = 0; p<needs.size(); p++){
                if(needs[p] < special[s][p]) {chk = false; break;}
            }
            if(chk){
                vector<int> tmp = needs;
                for(int p = 0; p<needs.size(); p++){
                    needs[p] -= special[s][p];
                }
                ans = min(ans, special[s][needs.size()] + rec(i, price, special, needs));
                needs = tmp;
            }
        }
        return dp[needs] = ans;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        dp.clear();
        return rec(0, price, special, needs);
    }
};