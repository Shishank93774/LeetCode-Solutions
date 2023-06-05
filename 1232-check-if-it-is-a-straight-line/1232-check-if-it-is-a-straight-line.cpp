class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c){
        int n = c.size();
        if(n == 2)return true;
        int dx = c[1][0] - c[0][0];
        int dy = c[1][1] - c[0][1];
        int cx,cy;
        for(int i=1;i<n-1;i++){
          cx = c[i+1][0] - c[i][0];
          cy = c[i+1][1] - c[i][1];
          if(dy*cx != dx*cy)return false;
        }
        return true;
    }
};