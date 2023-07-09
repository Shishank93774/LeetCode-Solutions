//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<int> powsOf5;
bool done = false;

class Solution
{
    public:
        int findNum(int n)
        {
            //complete the function here
            if(!done){
                powsOf5.push_back(5);
                while(powsOf5.back() < INT_MAX/5) powsOf5.push_back(powsOf5.back()*5);
                done = true;
            }
            int l = 5, r = 40015;
            
            auto chk = [&](int x){
                int have = 0;
                for(int xx: powsOf5) have += x/xx;
                return (have >= n);
            };
            
            while(l<=r){
                int mid = l + (r - l)/2;
                if(chk(mid)) r = mid - 1;
                else l = mid + 1;
            }
            return r + 1;
        }
};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}
// } Driver Code Ends