bool dp[31][21];
int n, m;
char sc, pc, pslc;

class Solution {    
public:
    bool isMatch(string str, string pat) {    
        n = pat.size(), m = str.size();
        for(int i = 0; i<n + 1; i++){
            for(int j = 0; j<m + 1; j++){
                if(i == 0 and j == 0){
                    dp[i][j] = true;
                }else if(i == 0){
                    dp[i][j] = false; 
                }else if(j == 0){
                    pc = pat[i-1];
                    if(pc == '*'){
                        dp[i][j] = dp[i-2][j];
                    }else{
                        dp[i][j] = false;
                    }
                }else{
                    sc = str[j-1];
                    pc = pat[i-1];
                    if(pc == '*'){
                        dp[i][j] = dp[i-2][j];
                        pslc = pat[i-2];
                        if(pslc == sc or pslc == '.'){
                            dp[i][j] = dp[i][j] or dp[i][j-1];
                        }
                    }else if(pc == sc or pc == '.'){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[n][m];
    }
};