class Solution {
public:
    int bestClosingTime(const string &customers) {
        int n = customers.size();
        int ans = n;
        vector<int> suf(n+1);
        suf[n] = 0;
        for(int i = n-1; i>=0; i--) suf[i] = suf[i+1] + (customers[i] == 'Y');
        
        int pref = 0, mn = n;
        for(int i = 0; i<=n; i++){
            if(mn > pref + suf[i]){
                mn = pref + suf[i];
                ans = i;
            }
            pref += (customers[i] == 'N');
        }
        return ans;
    }
};