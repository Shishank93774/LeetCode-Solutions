class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0, i = 0, n = arr.size();
        bool up = false, down = false;
        while(i+1<n){
            if(arr[i] < arr[i+1]){
                int begin = i;
                while(i+1<n and arr[i] < arr[i+1]) i++, up = true;
                while(i+1<n and arr[i] > arr[i+1]) i++, down = true;
                if(up and down) ans = max(ans, i - begin + 1);
                up = down = false;
            }else{
                i++;
            }
        }
        return ans;
    }
};