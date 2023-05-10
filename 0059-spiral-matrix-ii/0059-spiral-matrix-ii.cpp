class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > arr(n, vector<int>(n));
        int cur = 1;
        int tr = 0, br = n-1, lc = 0, rc = n-1;
        int r = 0, c = 0;
        while(tr<=br and lc<=rc){
            while(c<=rc){
                arr[r][c] = cur++;
                c++;
            }
            c--;
            r++;
            tr++;

            if(tr > br or lc > rc) break;
            while(r<=br){
                arr[r][c] = cur++;
                r++;
            }
            r--;
            c--;
            rc--;

            if(tr > br or lc > rc) break;
            while(c>=lc){
                arr[r][c] = cur++;
                c--;
            }
            c++;
            r--;
            br--;
            if(tr > br or lc > rc) break;
            while(r>=tr){
                arr[r][c] = cur++;
                r--;
            }
            r++;
            c++;
            lc++;
        }
        return arr;
    }
};