class Solution {
public:
    int minAbsDifference(vector<int>& arr, int goal) {
        int ans = INT_MAX, n = arr.size();
        
        vector<int> fhalf, shalf;
        for(int i = 0; i<n/2; i++) fhalf.push_back(arr[i]);
        for(int i = n/2; i<n; i++) shalf.push_back(arr[i]);
        
        set<int> fsubsets;
        vector<int> ssubsets;
        
        int sz = fhalf.size();
        fsubsets.insert(0);
        for(int mask = 1; mask<(1ll<<sz); mask++){
            int sum = 0;
            for(int j = 0; j<sz; j++){
                if(mask&(1ll<<j)){
                    sum += fhalf[j];
                }
            }
            fsubsets.insert(sum);
        }
        
        sz = shalf.size();
        ssubsets.push_back(0);
        for(int mask = 1; mask<(1ll<<sz); mask++){
            int sum = 0;
            for(int j = 0; j<sz; j++){
                if(mask&(1ll<<j)){
                    sum += shalf[j];
                }
            }
            ssubsets.push_back(sum);
        }
        sort(ssubsets.begin(), ssubsets.end());
        
        for(int x: fsubsets){
            int req = goal - x;
            int idx = lower_bound(ssubsets.begin(), ssubsets.end(), req) - ssubsets.begin();
            if(idx > 0) ans = min(ans, abs(goal - x - ssubsets[idx-1]));
            if(idx<ssubsets.size()) ans = min(ans, abs(goal - x - ssubsets[idx]));
        }
        return ans;
    }
};