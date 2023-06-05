class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& arr) {
        int n = arr.size();
        for(int i = 2; i<n; i++){
            int x1 = arr[i-2][0], y1 = arr[i-2][1];
            int x2 = arr[i-1][0], y2 = arr[i-1][1];
            int x3 = arr[i][0], y3 = arr[i][1];
            if((y2 - y1)*(x3 - x2) != (y3-y2)*(x2-x1)) return false;
        }
        return true;
    }
};