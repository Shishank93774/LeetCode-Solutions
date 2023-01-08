class Solution {
    double getSlope(vector<int> &v1, vector<int> &v2){
        if(v2[0] == v1[0]) return INT_MAX;
        return 1.0*(v2[1] - v1[1])/(1.0*(v2[0] - v1[0]));
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int mx = 1;
        for(int i = 0; i<n; i++){
            unordered_map<double, int> mp;
            for(int j = i+1; j<n; j++){
                mp[getSlope(points[i], points[j])]++;
            }
            for(auto it: mp) mx = max(mx, it.second+1);
        }
        return mx;
    }
};