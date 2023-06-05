class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& arr) {
        int n = arr.size();
        int x1 = arr[0][0], y1 = arr[0][1], x2 = arr[1][0], y2 = arr[1][1],x3,y3;
        for(int i = 2; i<n; i++){
            x3 = arr[i][0], y3 = arr[i][1];
            if((y2 - y1)*(x3 - x2) != (y3-y2)*(x2-x1)) return false;
        }
        return true;
    }
};