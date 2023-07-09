class Solution {
public:
    int largestVariance(string &str) {
        int n = str.size();
        int ans = 0;
        for(char f = 'a'; f<='z'; f++){
            for(char s = 'a'; s<='z'; s++){
                if(f == s) continue;
                for(int run = 1; run<=2; run++){
                    int i = 0;
                    int cntf = 0, cnts = 0;
                    int res = 0;
                    while(i<n){
                        if(str[i] == f) cntf++;
                        else if(str[i] == s) cnts++;
                        if(cnts > cntf){
                            cntf = cnts = 0;
                        }
                        res = cntf - cnts;
                        if(cntf and cnts) ans = max(ans, res);
                        i++;
                    }
                    reverse(str.begin(), str.end());
                }
            }
        }
        return ans;
    }
};