class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        bool unsetRow0 = false;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(arr[i][j] == 0){
                    if(i == 0) unsetRow0 = true;
                    else arr[i][0] = 0;
                    arr[0][j] = 0;
                }
            }
        }
        for(int i = n-1; i>0; i--){
            for(int j = m-1; j>=0; j--){
                if(arr[i][0] == 0 or arr[0][j] == 0) arr[i][j] = 0;
            }
        }
        if(unsetRow0){
            for(int j = 0; j<m; j++) arr[0][j] = 0;
        }
    }
};