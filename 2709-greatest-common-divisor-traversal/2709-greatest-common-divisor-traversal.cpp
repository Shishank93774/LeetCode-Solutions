#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define fo(iter, start_value, less_than) for(int iter = start_value; iter<less_than; iter++)

#define noans cout<<"-1"
#define zero cout<<"0"
#define nline "\n"
#define space " "
#define MSBll(n) __lg(n)
#define vi vector<int> 
#define vpii vector<pair<int, int> > 
#define vvi vector<vector<int> > 
#define set_bits __builtin_popcountll
#define getunique(x) {sort(all(x)); x.erase(unique(all(x)), x.end());}
#define mem(x, val) memset(x, val, sizeof(x))

struct DSU {
  vector<int> par, rnk, sz;  
  int c;
  DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {  // Constructor.
    for (int i = 1; i <= n; ++i) par[i] = i;
  }
  int find(int i) {
    return (par[i] == i ? i : (par[i] = find(par[i])));  // Path Compression along with find()
  }
  bool same(int i, int j) {
    return find(i) == find(j);  // is Connected?
  }
  int get_size(int i) {
    return sz[find(i)];
  }
  int count() {
    return c;    //connected components.
  }
  int merge(int i, int j) {  // Union funtion.
    if ((i = find(i)) == (j = find(j))) return -1;
    else --c;
    if (rnk[i] > rnk[j]) swap(i, j);
    par[i] = j;
    sz[j] += sz[i];
    if (rnk[i] == rnk[j]) rnk[j]++;
    return j;
  }
};

namespace number_theory {
 int gcd(int x, int y) {
 if (x == 0) return y;
   if (y == 0) return x;
return gcd(y, x % y);
}
bool isprime(int n) { 
if (n <= 1) return false; 
if (n <= 3) return true; 

if (n % 2 == 0 || n % 3 == 0) return false; 

for (int i = 5; i * i <= n; i += 6) 
if (n % i == 0 || n % (i+2) == 0) 
return false; 

return true; 
} 

int prime[15000105]; 
void sieve(int n) { 
  for (int i = 0; i <= n; i++) prime[i] = 1;
  for (int p = 2; p * p <= n; p++) { 
if (prime[p] == true) { 
  for (int i = p * p; i <= n; i += p) 
 prime[i] = false; 
} 
  } 
  prime[1] = prime[0] = 0;
} 
 
vector<int> primelist;
bool __primes_generated__ = 0;
 
void genprimes(int n) {
  __primes_generated__ = 1;
  sieve(n + 1);
  for (int i = 2; i <= n; i++) if (prime[i]) primelist.push_back(i);
}
 
vector<int> factors(int n) {
  if (!__primes_generated__) {
cerr << "Caint genprimes you dope" << endl;
exit(1);
  }
  vector<int> facs;
 
  for (int i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
if (n % primelist[i] == 0) {
while (n % primelist[i] == 0) {
n /= primelist[i];
facs.push_back(primelist[i]);
 }
}
  }
  if (n > 1) {
facs.push_back(n);
  }
  sort(facs.begin(), facs.end());
  return facs;
}

vector<int> getdivs(int n) {
    vector<int> divs;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        divs.push_back(i);
        divs.push_back(n / i);
      }
    }

    getunique(divs);
    return divs;
  }
}

using namespace number_theory;

class Solution {
    bool done;
    void pre(){
        done = true;
        genprimes(100005);
    }
public:
    bool canTraverseAllPairs(vector<int>& arr) {
        if(!done) pre();
        int n = arr.size();
        vector<int> facii[100005];
        DSU d(n);
        for(int i = 0; i<n; i++){
            int x = arr[i];
            vector<int> prm = factors(x);
            for(int x: prm){
                facii[x].push_back(i);
            }
        }
        for(int i = 0; i<100005; i++){
            for(int j = 1; j<facii[i].size(); j++){
                d.merge(facii[i][j], facii[i][0]);
            }
        }
        return (d.c == 1);
    }
};