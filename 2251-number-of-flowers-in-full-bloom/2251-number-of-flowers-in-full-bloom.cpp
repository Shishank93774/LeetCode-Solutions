class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> mp;
        for(auto &v: flowers){
            mp[v[0]]++;
            mp[v[1]+1]--;
        }
        int sum = 0;
        vector<pair<int, int> > arr;
        arr.push_back({0, 0});
        for(auto [v, f]: mp){
            sum += f;
            arr.push_back({v, sum});
        }
        // for(int i = 0; i<arr.size(); i++){
        //     cout<<arr[i].first<<" "<<arr[i].second<<"\n";
        // }
        vector<int> ans(people.size());
        
        auto bs = [&](int x){
            int l = 0, r = arr.size() - 1;
            while(l<=r){
                int mid = l + (r - l)/2;
                if(arr[mid].first <= x) l = mid + 1;
                else r = mid - 1;
            }
            // cout<<arr[l-1].first<<"\n";
            return arr[l-1].second;
        };
        
        for(int i = 0; i<people.size(); i++){
            ans[i] = bs(people[i]);
        }
        return ans;
    }
};