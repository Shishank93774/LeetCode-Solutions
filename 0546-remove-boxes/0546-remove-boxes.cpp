int dp[101][101][101];
class Solution {
public:
    int removeBoxes(vector<int> &boxes) {
        
        int n = boxes.size();
        vector<vector<int> > arr;
        arr.push_back({boxes[0], 1});
        int i = 1;
        while(i<n){
            if(boxes[i] == arr.back()[0]){
                arr.back()[1]++;
            }else{
                arr.push_back({boxes[i], 1});
            }
            i++;
        }
        memset(dp, -1, sizeof dp);
        n = arr.size();
        auto rec = [&](int l, int r, int ex, auto &&rec)->int{
            if(l > r) return 0;
            if(dp[l][r][ex] != -1) return dp[l][r][ex];
            int ans = (arr[l][1]+ex)*(arr[l][1]+ex) + rec(l+1, r, 0, rec);
             
            for(int k = l+2; k<=r; k++){
                if(arr[l][0] == arr[k][0])
                    ans = max(ans, rec(l+1, k-1, 0, rec) + rec(k, r, arr[l][1] + ex, rec));
            }
            return dp[l][r][ex] = ans;
        };
        
        return rec(0, n-1, 0, rec);
        
    }
};