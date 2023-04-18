//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int dxy[8][2] = {{0, 1}, {1, 0}, 
                 {0, -1}, {-1, 0},
                 {1, -1}, {-1, 1},
                 {1, 1}, {-1, -1}
};
bool vis[101][101];
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n = grid.size(), m = grid[0].size();
	    auto dfs = [&](int r, int c, int i, int id, auto&& dfs)->bool {
	        if(i == word.size()) return true;
	        if(r<0 or c<0 or r>=n or c>=m or vis[r][c] or grid[r][c] != word[i]) return false;
	        vis[r][c] = true;
	        return dfs(r + dxy[id][0], c + dxy[id][1], i+1, id, dfs);
	    };
	    vector<vector<int>> ans;
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<m; j++){
	            for(int id = 0; id<8; id++){
	                memset(vis, false, sizeof vis);
	                if(dfs(i, j, 0, id, dfs)){
	                    ans.push_back({i, j});
	                    break;
	                }
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends