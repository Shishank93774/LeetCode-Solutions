class Solution {
public:
    int largestVariance(string &str) {
        int n = str.size();
        int ans = 0;
        unordered_set<char> st(str.begin(), str.end());
        for(char f : st){
            for(char s : st){
                if(f == s) continue;
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
            }
        }
        reverse(str.begin(), str.end());
        for(char f : st){
            for(char s : st){
                if(f == s) continue;
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
            }
        }
        return ans;
    }
};