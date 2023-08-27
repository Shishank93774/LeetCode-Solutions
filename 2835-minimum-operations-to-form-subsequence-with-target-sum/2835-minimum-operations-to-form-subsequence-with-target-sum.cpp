class Solution {
public:
    int minOperations(vector<int>& arr, int x) {
        int n = arr.size();
        map<int, int> mp;
        for(int x: arr) mp[x]++;
        
        int ans = 0;
        int lowestNotSet = -1;
        for(int b = 0; b<31; b++){
            if(x&(1<<b)){
                if(mp[(1<<b)]){
                    mp[(1<<b)]--;
                    // x ^= (1<<b);
                }else{
                    if(lowestNotSet == -1)
                        lowestNotSet = b;
                }
                if(lowestNotSet != -1){
                    if(mp[(1<<b)]){
                        ans += (b - lowestNotSet);
                        mp[(1<<b)]--;
                        lowestNotSet = -1;
                    }else{
                    }
                }
            }else{
                if(lowestNotSet != -1){
                    if(mp[(1<<b)]){
                        ans += (b - lowestNotSet);
                        mp[(1<<b)]--;
                        lowestNotSet = -1;
                    }else{
                    }
                }
            }
            mp[(1<<(b+1))] += (mp[(1<<b)]/2);
        }
        if(lowestNotSet == -1) return ans;
        return -1;
    }
};