class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time(n);
        for(int i = 0; i<n; i++){
            time[i] = (dist[i]+speed[i]-1)/speed[i];
        }
        sort(time.begin(), time.end());
        int cur = 1;
        for(int i = 0; i<n; i++, cur++){
            if(cur > time[i]) return i;
        }
        return n;
    }
};