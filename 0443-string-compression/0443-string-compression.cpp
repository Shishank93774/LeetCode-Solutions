class Solution {
public:
    int compress(vector<char>& arr) {
        string ans;
        int i = 0, n = arr.size();
        while(i<n){
            int j = i + 1;
            while(j<n and arr[i] == arr[j]) j++;
            int cnt = j - i;
            ans += arr[i] + ((cnt>1)?to_string(cnt):"");
            i = j;
        }
        arr.clear();
        for(char ch: ans) arr.push_back(ch);
        return arr.size();
    }
};