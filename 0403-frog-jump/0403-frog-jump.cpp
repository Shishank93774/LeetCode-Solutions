int dp[2001][2001];
class Solution {
public:
    bool canCross(vector<int>& arr) {
        int n = arr.size();
        
        if(arr[1] != 1) return false;
        
        memset(dp, -1, sizeof dp);
        auto bs = [&](int l, int x)->int{
            int r = n-1;
            while(l<=r){
                int mid = l + (r - l)/2;
                if(arr[mid] == x) return mid;
                else if(arr[mid] < x) l = mid + 1;
                else r = mid - 1;
            }
            return -1;
        };
        
        auto rec = [&](int i, int prv, auto &&rec)->int{
            if(i == n-1) return true;
            
            int &ans = dp[i][prv];
            if(ans != -1) return ans;
            ans = false;
            int nxt = arr[i] + (prv-1);
            int nxtpos = bs(i+1, nxt);
            if(nxtpos != -1){
                ans = rec(nxtpos, prv-1, rec);
            }
            if(ans) return true;
            
            nxt = arr[i] + prv;
            nxtpos = bs(i+1, nxt);
            if(nxtpos != -1){
                ans = rec(nxtpos, prv, rec);
            }
            if(ans) return true;
            
            nxt = arr[i] + prv + 1;
            nxtpos = bs(i+1, nxt);
            if(nxtpos != -1){
                ans = rec(nxtpos, prv+1, rec);
            }
            if(ans) return true;
            return false;           
        };
        
        return rec(1, 1, rec);
        
    }
};