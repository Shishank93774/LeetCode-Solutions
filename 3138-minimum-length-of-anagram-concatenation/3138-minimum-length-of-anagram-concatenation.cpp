class Solution {
public:
    int minAnagramLength(const string &str) {
        int n = str.size();
        
        vector<vector<int> > pre(n+1, vector<int>(26, 0));
        for(int i = 1; i<=n; i++){
            for(int c = 0; c<26; c++){
                pre[i][c] = pre[i-1][c];
            }
            pre[i][(str[i-1] - 'a')]++;
            if(i == n and pre[i][(str[i-1] - 'a')] == n) return 1;
        }
        
        int ans = n;
        
        for(int x = 2; x*x<=n; x++){
            if(n%x == 0){
                bool chk = true;
                vector<int> f(26);
                for(int c = 0; c<26; c++){
                    f[c] = pre[x][c] - pre[0][c];
                }
                
                for(int i = 2*x; i<=n; i+=x){
                    for(int c = 0; c<26; c++){
                        if(f[c] != pre[i][c] - pre[i-x][c]){
                            chk = false; break;
                        }
                    }
                    if(!chk) break;
                }
                if(chk) return min(ans, x);
                
                int tx = x;
                x = n/x;
                chk = true;
                
                for(int c = 0; c<26; c++){
                    f[c] = pre[x][c] - pre[0][c];
                }
                
                for(int i = 2*x; i<=n; i+=x){
                    for(int c = 0; c<26; c++){
                        if(f[c] != pre[i][c] - pre[i-x][c]){
                            chk = false; break;
                        }
                    }
                    if(!chk) break;
                }
                if(chk) ans = min(ans, x);
                
                x = tx;
                
            }
        }
        
        return ans;
        
    }
};