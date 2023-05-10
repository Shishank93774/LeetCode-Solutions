int N = 9;
int starts[9][2] = {{0, 0}, {0, 3}, {0, 6},
                    {3, 0}, {3, 3}, {3, 6},
                    {6, 0}, {6, 3}, {6, 6}};

int dir[9][2] = {{0, 0}, {0, 1}, {0, 2},
                 {1, 0}, {1, 1}, {1, 2},
                 {2, 0}, {2, 1}, {2, 2}};

class Solution {
    bool valid(int r, int c, char v, vector<vector<char> > &arr){
        for(int j = 0; j<9; j++) if(arr[r][j] == v) return false;
        for(int i = 0; i<9; i++) if(arr[i][c] == v) return false;
        int br = r/3, bc = c/3;
        int t = br*3 + bc;
        int x = starts[t][0], y = starts[t][1];
        for(int j = 0; j<9; j++){
            int tx = x + dir[j][0], ty = y + dir[j][1];
            if(arr[tx][ty] == v) return false;
        }
        return true;
    }
    bool rec(int r, int c, vector<vector<char> > &arr){
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