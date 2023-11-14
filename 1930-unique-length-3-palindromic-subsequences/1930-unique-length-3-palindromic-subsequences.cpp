class Solution {
public:
    int countPalindromicSubsequence(const string &str) {
        int n = str.size();
        vector<int> f(26, n), l(26, -1);
        for(int i = 0; i<n; i++){
            int id = str[i] - 'a';
            f[id] = min(f[id], i);
            l[id] = max(l[id], i);
        }
        int ans = 0;
        
        for(int fl = 0; fl<26; fl++){
            int s = f[fl]+1, e = l[fl]-1;
            int mask = 0;
            int cnt = 0;
            for(;s<=e;s++){
                int id = str[s] - 'a';
                if(!(mask&(1<<id))) ans++;
                mask |= (1<<id);
            }
        }
        
        return ans;
    }
};