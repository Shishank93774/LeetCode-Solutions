vector<vector<double> > dp(176, vector<double>(176, -1.0));

class Solution {
public:
    double soupServings(int n) {
        
        if(n >= 4375) return 1.0;
        
        auto rec = [&](int rema, int remb, auto &&rec)->double{
            if(rema <= 0 and remb <=0) return 0.5;
            if(rema <= 0) return 1.0;
            if(remb <= 0) return 0.0;
            
            if(dp[rema][remb] != -1.0) return dp[rema][remb];
            
            double &prob = dp[rema][remb] = 0.0;
            
            prob += 0.25*rec(rema-4, remb, rec);
            prob += 0.25*rec(rema-3, remb-1, rec);
            prob += 0.25*rec(rema-2, remb-2, rec);
            prob += 0.25*rec(rema-1, remb-3, rec);
            
            return prob;
            
        };
        
        return rec((n+24)/25, (n+24)/25, rec);
    }
};