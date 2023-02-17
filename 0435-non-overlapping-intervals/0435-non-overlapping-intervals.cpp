class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), [](const vector<int> &v1, const vector<int> &v2){
           return v1[1] < v2[1]; 
        });
        int ans = arr.size() - 1;        
        int end = arr[0][1];
        for(int i = 1; i<arr.size(); i++){
            if(arr[i][0] >= end){
                end = arr[i][1];
                ans--;
            }
        }
        return ans;
    }
};