class Solution {
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int> > ans;
        int i = 0, n = intervals.size();

        int idx = upper_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        if(idx != n) intervals.insert(intervals.begin() + idx, newInterval);
        else intervals.push_back(newInterval);
        n++;
        
        auto overlaps = [](vector<int> &v1, vector<int> &v2) ->bool {
            return min(v1[1], v2[1]) - max(v1[0], v2[0]) >= 0;
        };
        
        auto mergeIntervals = [](vector<int> &v1, vector<int> &v2) ->vector<int> {
            return {min(v1[0], v2[0]), max(v1[1], v2[1])};
        };
        
        while(i<n){
            vector<int> curInterval = intervals[i];
            while(i<n and overlaps(curInterval, intervals[i])){
                curInterval = mergeIntervals(curInterval, intervals[i]);
                i++;
            }
            ans.push_back(curInterval);
        }
        return ans;
    }
};