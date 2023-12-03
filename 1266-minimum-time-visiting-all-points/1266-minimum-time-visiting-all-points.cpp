class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int x = points[0][0], y = points[0][1];
        
        for(int i = 1; i<points.size(); i++){
            int xd = points[i][0], yd = points[i][1];
            int dx = abs(x - xd), dy = abs(y - yd);
            ans += max(dx, dy);
            x = xd, y = yd;
        }
        return ans;
    }
};