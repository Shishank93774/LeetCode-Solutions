class Solution {
    bool rec(int i, int j, vector<int> &arr, int s1, int s2, bool t){
        if(i == j){
            s1 += t*arr[i], s2 += (!t)*arr[j];
            return s1 >= s2;
        }
        if(t){
            bool chk = rec(i+1, j, arr, s1 + arr[i], s2, !t);
            if(chk) return true;
            chk = rec(i, j-1, arr, s1 + arr[j], s2, !t);
            if(chk) return true;
        }else{
            bool chk = rec(i+1, j, arr, s1, s2 + arr[i], !t);
            if(!chk) return false;
            chk = rec(i, j-1, arr, s1, s2 + arr[j], !t);
            if(!chk) return false;
            else return true;
        }
        return false;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        return rec(0, nums.size() - 1, nums, 0, 0, true);
    }
};