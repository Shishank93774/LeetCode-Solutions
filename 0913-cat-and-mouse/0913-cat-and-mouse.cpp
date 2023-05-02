const int N = 101;
int dp[6*N+100][N+1][N+1];

class Solution {
    int rec(int time, int tom, int jerry, bool turn, vector<vector<int> > &graph, int n){
        if(time == 6*n) return 0;
        if(tom == jerry) return 2;
        if(jerry == 0) return 1;
        if(dp[time][tom][jerry] != -1) return dp[time][tom][jerry];
        if(turn){
            bool draw = false;
            for(int nbr: graph[jerry]){
                int res = rec(time+1, tom, nbr, !turn, graph, n);
                if(res == 1) return dp[time][tom][jerry] = 1;
                if(res == 0) draw = true;
            }
            if(draw) return dp[time][tom][jerry] = 0;
            return dp[time][tom][jerry] = 2;
        }else{
            bool draw = false;
            for(int nbr: graph[tom]){
                if(nbr == 0) continue;
                int res = rec(time+1, nbr, jerry, !turn, graph, n);
                if(res == 2) return dp[time][tom][jerry] = 2;
                if(res == 0) draw = true;
            }
            if(draw) return dp[time][tom][jerry] = 0;
        }
        return dp[time][tom][jerry] = 1;
    }
public:
    int catMouseGame(vector<vector<int>>& graph) {
        memset(dp, -1, sizeof dp);
        return rec(0, 2, 1, true, graph, graph.size());
    }
};