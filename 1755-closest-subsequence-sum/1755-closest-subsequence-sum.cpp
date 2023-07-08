class Solution {
public:
    int minAbsDifference(vector<int>& arr, int goal) {
        int ans = INT_MAX, n = arr.size();
        
        vector<int> fhalf, shalf;
        for(int i = 0; i<n/2; i++) fhalf.push_back(arr[i]);
        for(int i = n/2; i<n; i++) shalf.push_back(arr[i]);
        
        set<int> fsubsets, ssubsets;
        
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
        ssubsets.insert(0);
        for(int mask = 1; mask<(1ll<<sz); mask++){
            int sum = 0;
            for(int j = 0; j<sz; j++){
                if(mask&(1ll<<j)){
                    sum += shalf[j];
                }
            }
            ssubsets.insert(sum);
        }
        
        for(int x: fsubsets){
            int req = goal - x;
            auto it = ssubsets.upper_bound(req);
            if(it != ssubsets.end()) ans = min(ans, abs(req - *it));
            if(it != ssubsets.begin()){
                it--;
                ans = min(ans, abs(req - *it));
            }

        }
        return ans;
    }
};