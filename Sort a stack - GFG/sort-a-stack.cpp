//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void sortStack(stack<int> &stk){
    if(stk.size() <= 1) return;
    
    int tp = stk.top(); stk.pop();
    sortStack(stk);
    
    vector<int> tmp;
    while(!stk.empty() and stk.top() > tp){
        tmp.push_back(stk.top()); stk.pop();
    }
    stk.push(tp);
    while(!tmp.empty()){
        stk.push(tmp.back());
        tmp.pop_back();
    }
}

void SortedStack :: sort()
{
   //Your code here
   sortStack(s);
}