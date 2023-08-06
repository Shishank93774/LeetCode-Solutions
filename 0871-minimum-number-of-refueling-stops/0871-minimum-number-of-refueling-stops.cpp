class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int dist = startFuel;
        int refills = 0;
        int i = 0, n = stations.size();
        priority_queue<vector<int> > pqu;
        while(dist < target){
            while(i<n and stations[i][0] <= dist){
                pqu.push({stations[i][1], stations[i][0]});
                i++;
            }
            
            if(pqu.empty()) return -1;
            
            refills++;
            dist += pqu.top()[0]; pqu.pop();
        }
        
        return refills;
        
    }
};