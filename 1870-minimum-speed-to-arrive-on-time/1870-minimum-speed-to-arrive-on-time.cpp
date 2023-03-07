class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 1e8, n = dist.size();
        int ans = -1;
        while(l<=r){
            int mid = l + (r - l)/2;
            int i = 0;
            int timeTaken = 0;
            while(i+1<n){
                timeTaken += (dist[i++] + mid - 1)/mid;
            }
            double netTime = timeTaken + 1.0*dist[n-1]/mid;
            if(netTime <= hour){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};