int cur[1001];
class Solution {
public:
    
    int numDistinct(string &str, string &sub) {
        int n = str.size(), m = sub.size();
        for(int j = 0; j<m; j++) cur[j] = 0;
        cur[m] = 1;
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<m; j++){
                cur[j] = 1ll*cur[j] + (str[i] == sub[j])*cur[j+1];
            }
        }
    
        return cur[0];
    }
};