#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define fo(iter, start_value, less_than) for(int iter = start_value; iter 
#define vpii vector > 
#define vvi vector > 
#define set_bits __builtin_popcountll
#define getunique(x) {sort(all(x)); x.erase(unique(all(x)), x.end());}
#define mem(x, val) memset(x, val, sizeof(x))

// const double PI = 3.1415926535897932384626433832795;
// const string pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
const int MOD = 1e9+7;
// const int MOD = 998244353;
const ll INF = 1e18;
// const int N = 1e5+5;
// const int N = 2e5+5;
// const int N = 3e5+5;
// const int MX = INT_MAX;
// const int MN = INT_MIN;

// #define int ll


#define yes cout<<"YES"
#define no cout<<"NO"
//set MULTISET ka bhi dekh lena bhai



void fun(){
    int n, k; cin>>n>>k;
    vector<int> arr(n);
    for(int &x: arr) cin>>x;
    
    priority_queue<int, vector<int>, greater<int> > pqu;
    for(int i = 0; i<n; i++){
        pqu.push(arr[i]);
        if(pqu.size() > k){
            cout<<pqu.top()<<" ";
            pqu.pop();
        }
    }
    
    while(pqu.size()){
        cout<<pqu.top()<<" ";
        pqu.pop();
    }
    
}

signed main() {
// #ifndef ONLINE_JUDGE
//  freopen("Error.txt", "w", stderr);
// #endif
    fastio();
    cout << setprecision(15) << fixed;
    int _CASE = 1;
    int _TC = 1;cin>>_TC;while(_TC--)
    // cout<<"Case #"<<_CASE++<<": ",
    fun(),cout<<"\n";
    return 0;
}