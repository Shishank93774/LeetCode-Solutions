class Solution {
    int getLis(vector<vector<int>>& arr){
        int n = arr.size();
        if(n == 0) return 0;
        sort(arr.begin(), arr.end(), [](vector<int> &v1, vector<int> &v2){
            return v1[0] == v2[0]? v1[1]>v2[1]: v1[0]<v2[0];
        });
        vector<int> lis;
        lis.push_back(arr[0][1]);
        for(int i = 1; i<n; i++){
            if(lis.back() < arr[i][1]) lis.push_back(arr[i][1]);
            else{
                auto it = lower_bound(lis.begin(), lis.end(), arr[i][1]);
                *it = arr[i][1];
            }
        }
        return lis.size();
    }
public:
    int maxPathLength(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> sml, lar;
        
        for(auto v: arr){
            if(v[0] < arr[k][0] and v[1] < arr[k][1]) sml.push_back(v);
            if(v[0] > arr[k][0] and v[1] > arr[k][1]) lar.push_back(v);
        }
        
        return getLis(sml) + getLis(lar) + 1;
    }
};