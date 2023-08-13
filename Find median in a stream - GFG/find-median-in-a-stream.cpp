//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    priority_queue<int> mxpqu;
    priority_queue<int, vector<int>, greater<int> > mnpqu;
    public:
    //Function to insert heap.
    void insertHeap(int &num)
    {
        int mxtp = INT_MIN;
        int mntp = INT_MAX;
        if(mnpqu.size()) mntp = mnpqu.top();
        if(mxpqu.size()) mxtp = mxpqu.top();
        if(num >= mntp) mnpqu.push(num);
        else mxpqu.push(num);
        
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(mnpqu.size() > mxpqu.size() + 1){
            mxpqu.push(mnpqu.top()); mnpqu.pop();
        }
        if(mxpqu.size() > mnpqu.size() + 1){
            mnpqu.push(mxpqu.top()); mxpqu.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        double md = 0.0;
        if(mnpqu.size() == mxpqu.size()){
            md = 1.0*(mnpqu.top() + mxpqu.top())/2;
        }else{
            md = mxpqu.size() > mnpqu.size()?mxpqu.top():mnpqu.top();
        }
        return md;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends