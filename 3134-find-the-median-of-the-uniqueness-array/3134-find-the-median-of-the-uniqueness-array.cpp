#define ll long long
class Solution {
public:
    int medianOfUniquenessArray(vector<int>& arr) {
        
        int n = arr.size();
        int l = 1, r = n;
        
        ll median = (1ll*n*(n+1)/2+1)/2;
        
        auto chk = [&](int x){
            unordered_map<int, int> mp;
            
            int i = 0;;
            ll cnt = 0;
            for(int j = 0; j<n; j++){
                mp[arr[j]]++;
                while(mp.size() > x){
                    if(--mp[arr[i]] == 0) 
                        mp.erase(arr[i]);
                    i++;
                }
                cnt += (j - i + 1);
            }
            
            return cnt;
        };
        
        while(l<=r){
            int mid = l + (r - l)/2;
            
            if(chk(mid) < median) l = mid + 1;
            else r = mid - 1;
        }
        
        return l;
    }
};