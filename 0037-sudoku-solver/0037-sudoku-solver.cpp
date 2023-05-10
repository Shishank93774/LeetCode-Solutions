short N = 9;
short starts[9][2] = {{0, 0}, {0, 3}, {0, 6},
                    {3, 0}, {3, 3}, {3, 6},
                    {6, 0}, {6, 3}, {6, 6}};

short dir[9][2] = {{0, 0}, {0, 1}, {0, 2},
                 {1, 0}, {1, 1}, {1, 2},
                 {2, 0}, {2, 1}, {2, 2}};

class Solution {
    bool valid(short r, short c, char v, vector<vector<char> > &arr){
        for(short j = 0; j<9; j++) if(arr[r][j] == v or arr[j][c] == v) return false;
        short br = r/3, bc = c/3;
        short t = br*3 + bc;
        short x = starts[t][0], y = starts[t][1];
        for(short j = 0; j<9; j++){
            short tx = x + dir[j][0], ty = y + dir[j][1];
            if(arr[tx][ty] == v) return false;
        }
        return true;
    }
    bool rec(short r, short c, vector<vector<char> > &arr){
        if(r == 9) return true;
        if(c == 9) return rec(r+1, 0, arr);
        if(arr[r][c] != '.') return rec(r, c+1, arr);
        for(char v = '1'; v <= '9'; v++){
            if(valid(r, c, v, arr)){
                arr[r][c] = v;
                if(rec(r, c, arr)) return true;
                arr[r][c] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        rec(0, 0, board);
    }
};