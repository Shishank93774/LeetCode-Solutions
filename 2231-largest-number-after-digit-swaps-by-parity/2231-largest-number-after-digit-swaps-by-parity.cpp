class Solution {
public:
    int largestInteger(int num) {
        string str = to_string(num);
        string ans = str;
        unordered_map<int, bool> mp;
        string odd, eve;
        int n = str.size();
        for(int i = 0; i<n; i++){
            char ch = str[i];
            if((ch-'0')%2 == 0){
                eve += ch;
                mp[i] = true;
            }else{
                odd += ch;
                mp[i] = false;
            }
        }
        sort(odd.rbegin(), odd.rend());
        sort(eve.rbegin(), eve.rend());
        int j = 0, k = 0;
        for(int i = 0; i<n; i++){
            if(!mp[i]) ans[i] = odd[j++];
            else ans[i] = eve[k++];
        }
        return stoi(ans);
    }
};