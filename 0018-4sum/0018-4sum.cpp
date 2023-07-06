class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int x) {
        set<vector<int> > ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0; i+3<n; i++){
            for(int j = 3; j<n; j++){
                int l = i+1, r = j-1;
                int tot = 1ll*arr[i] + arr[j];
                int req = 1ll*x - tot;
                while(l<r){
                    if(1ll*tot + arr[l] + arr[r] < x) l++;
                    else if(1ll*tot + arr[l] + arr[r] > x) r--;
                    else{
                        ans.insert({arr[i], arr[l], arr[r], arr[j]});
                        l++; r--;
                    }
                }
            }
        }
        return vector<vector<int> >(ans.begin(), ans.end());
    }
};