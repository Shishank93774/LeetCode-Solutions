class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0;
        for(int i = 0; i<bank.size(); i++){
            int cur = 0;
            for(int j = 0; j<bank[i].size(); j++) cur += (bank[i][j] == '1');
            ans += cur*prev;
            if(cur) prev = cur;
        }
        return ans;
    }
};