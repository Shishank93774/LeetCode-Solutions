class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int> > arr;
        int n = plantTime.size();
        for(int i = 0; i<n; i++) arr.push_back({plantTime[i], growTime[i]});
        
        sort(arr.begin(), arr.end(), [](const pair<int, int> &p1, const pair<int, int> &p2){
           return p1.second > p2.second; 
        });
        int ans = 0, cTime = 0;
        for(int i = 0; i<n; i++){
            cTime += arr[i].first;
            ans = max(ans, cTime + arr[i].second);
        }
        return ans;
    }
};