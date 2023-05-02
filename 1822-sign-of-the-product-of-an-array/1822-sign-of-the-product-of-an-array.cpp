class Solution {
public:
    int arraySign(vector<int>& arr) {
        int c0 = 0, cneg = 1;
        for(int x: arr) c0 +=(x==0), cneg +=(x<0);
        if(c0) return 0;
        return 2*(cneg%2)- 1;
    }
};