class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int l = 0, r = arr.size() - 1;
        while(l<r){
            if(arr[l]%2 and arr[r]%2){
                swap(arr[l], arr[--r]);
                r--;
            }else if(arr[l]%2){
                swap(arr[l++], arr[r--]);
            }else if(arr[r]%2){
                l++; r--;
            }else{
                swap(arr[++l], arr[r]);
                l++;
            }
        }
        return arr;
    }
};