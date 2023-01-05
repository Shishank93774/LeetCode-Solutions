class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), [](vector<int> &v1, vector<int> &v2){
            return v1[1]==v2[1]?v1[0]<v2[0]:v1[1]<v2[1];
        });
        int ans = 1;
        int cur = arr[0][1];
        for(int i = 1; i<n; i++){
            if(arr[i][0] <= cur){}
            else{
                ans++;
                cur = arr[i][1];
            }
        }
        return ans;
    }
};