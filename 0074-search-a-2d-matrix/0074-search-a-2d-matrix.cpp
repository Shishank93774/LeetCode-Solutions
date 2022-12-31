int n, m, outerL, outerR, outerMid, innerMid, innerL, innerR;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int x) {
        n = arr.size(), m = arr[0].size();
        outerL = 0, outerR = n - 1;
        while(outerL <= outerR){
            outerMid = outerL + (outerR - outerL)/2;
            if(x < arr[outerMid][0]){
                outerR = outerMid - 1;
            }else if(x > arr[outerMid][m-1]){
                outerL = outerMid + 1;
            }else{
                innerL = 0, innerR = m - 1;
                while(innerL <= innerR){
                    innerMid = innerL + (innerR - innerL)/2;
                    if(x < arr[outerMid][innerMid]){
                        innerR = innerMid - 1;
                    }else if(x > arr[outerMid][innerMid]){
                        innerL = innerMid + 1;
                    }else{
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};