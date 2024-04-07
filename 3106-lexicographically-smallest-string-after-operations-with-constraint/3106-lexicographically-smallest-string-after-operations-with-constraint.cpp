class Solution {
    int distFromA(char c){
        return min(c-'a', 'z' - c + 1);
    }
    char prv(char c){
        if(c == 'a') return 'z';
        return c-1;
    }
    char nxt(char c){
        if(c == 'z') return 'a';
        return c+1;
    }
public:
    string getSmallestString(string s, int k) {
        string ans = s;
        int n = s.size();
        for(int i = 0; i<n; i++){
            int d = distFromA(s[i]);
            if(d <= k){
                k -= d;
                ans[i] = 'a';
            }else{
                char mn = s[i];
                int tmp = k;
                char c = s[i];
                while(tmp--){
                    c = prv(c);
                    mn = min(mn, c);
                }
                c = s[i];
                tmp = k;
                while(tmp--){
                    c = nxt(c);
                    mn = min(mn, c);
                }
                ans[i] = mn;
                break;
            }
        }
        return ans;
    }
};