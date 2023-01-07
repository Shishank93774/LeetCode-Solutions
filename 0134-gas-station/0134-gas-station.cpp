class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        int tot = 0;
        for(int i = 0; i<n; i++) tot += gas[i] - cost[i];
        if(tot<0) return -1;
        
        int ans = 0;
        int net = 0;
        for(int i = 0; i<n; i++){
            net += gas[i] - cost[i];
            if(net<0) ans = i+1;
            net = max(0, net);
        }
        return ans;
    }
};