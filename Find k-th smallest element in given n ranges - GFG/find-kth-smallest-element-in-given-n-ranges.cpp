//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        sort(range.begin(), range.end());
        vector<vector<int> > vec;
        vec.push_back(range[0]);
        for(int i = 1; i<n; i++){
            if(vec.back()[1] >= range[i][0]){
                vec.back()[1] = max(range[i][1], vec.back()[1]);
            }else{
                vec.push_back(range[i]);
            }
        }
        vector<vector<int> > cnts;
        for(int i = 0; i<vec.size(); i++){
            cnts.push_back({vec[i][0], vec[i][1], vec[i][1] - vec[i][0] + 1});
        }
        vector<int> ans;
        for(int x: queries){
            x--;
            bool chk = false;
            for(int i = 0; i<cnts.size(); i++){
                if(x >= cnts[i][2]){
                    x -= cnts[i][2];
                }else{
                    chk = true;
                    ans.push_back(cnts[i][0] + x);
                    break;
                }
            }
            if(!chk) ans.push_back(-1);
        }
        return ans;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends