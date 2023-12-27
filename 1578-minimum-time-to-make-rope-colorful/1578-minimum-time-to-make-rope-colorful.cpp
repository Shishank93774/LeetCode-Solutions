class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int mxTime = neededTime[0];
        int ans = 0, sum = neededTime[0];
        for(int i = 1; i<colors.length(); i++){
            if(colors[i] != colors[i-1]){
                ans += sum - mxTime;
                sum = 0;
                mxTime = 0;
            }
            sum += neededTime[i];
            mxTime = max(mxTime, neededTime[i]);
        }
        ans += sum - mxTime;
        return ans;
    }
};