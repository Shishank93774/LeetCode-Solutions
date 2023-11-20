class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = travel.size();
        vector<int> pre(n+1);
        pre[0] = 0;
        for(int i = 1; i<=n; i++){
            pre[i] = pre[i-1] + travel[i-1];
        }
        unordered_map<char, int> lstPos, cnt;
        for(int i = 0; i<garbage.size(); i++){
            for(char c: garbage[i]){
                lstPos[c] = i;
                cnt[c]++;
            }
        }
        int ans = 0;
        
        for(char c: {'M', 'P', 'G'}){
            if(cnt[c]) ans += pre[lstPos[c]] + cnt[c];
        }
        
        return ans;
    }
};