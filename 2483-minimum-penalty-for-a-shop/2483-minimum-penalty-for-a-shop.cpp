class Solution {
public:
    int bestClosingTime(string str) {
        int n = str.size();
        vector<int> suf(n+1);
        suf[n] = 0;
        for(int i = n-1; i>=0; i--){
            suf[i] = suf[i+1] + (str[i] == 'Y');
        }
        int nso = 0, mn = n+1, idx = 0;
        for(int i = 0; i<=n; i++){
            int c = nso + suf[i];
            if(mn > c){
                mn = c;
                idx = i;
            }
            nso += str[i] == 'N';
        }
        return idx;
    }
};