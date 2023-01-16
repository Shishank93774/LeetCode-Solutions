const int N = 5e4+4;
int dp[N];

struct Job{
    int s, e, r;
    int id;
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> arr(n);
        for(int i = 0; i<n; i++){
            arr[i].s = startTime[i], arr[i].e = endTime[i], arr[i].r = profit[i];
        }
        sort(arr.begin(), arr.end(), [](const Job &j1, const Job &j2){
            return j1.e<j2.e;
        });
        for(int i = 0; i<n; i++) arr[i].id = i;
             
        auto maxInMin = [](const Job &j, const vector<Job> &arr) ->int{
            int s = j.s, l = 0, r = j.id - 1, res = -1;
            while(l<=r){
                int mid = (l+r)/2;
                if(arr[mid].e <= s){
                    res = mid;
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            return res;
        };
        
        dp[0] = 0;
        for(int i = 1; i<=n; i++){
            int a1 = dp[i-1];
            int a2 = arr[i-1].r;
            int loc = maxInMin(arr[i-1], arr);
            if(loc != -1) a2 += dp[loc+1];
            dp[i] = max(a1, a2);
        }
        return dp[n];
    }
};