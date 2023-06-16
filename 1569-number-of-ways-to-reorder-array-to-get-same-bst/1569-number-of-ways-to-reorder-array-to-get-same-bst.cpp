const int FAC_N = 1e3+1, mod = 1e9+7;
int  factorialNumInverse[FAC_N + 1], naturalNumInverse[FAC_N + 1], fact[FAC_N + 1]; 
void InverseofNumber(int  p){ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= FAC_N; i++) naturalNumInverse[i] = 1ll*naturalNumInverse[p % i] * (p - p / i) % p; 
}
void InverseofFactorial(int  p) { 
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= FAC_N; i++) factorialNumInverse[i] = (1ll*naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
}
void factorial(int  p) { 
    fact[0] = 1; 
    for (int i = 1; i <= FAC_N; i++) fact[i] = (1ll*fact[i - 1] * i) % p; 
} 
int  nCr(int  N, int  R, int  p = mod) { 
    int  ans = ((1ll * fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p; 
    return ans; 
}
bool done = false;

class Solution {
    int rec(vector<int> &arr, int n){
        if(n<=2) return 1;
        vector<int> left, right;
        for(int i = 1; i<n; i++){
            if(arr[i] < arr[0]) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }
        int ans = ((1ll*nCr(n-1, left.size())*rec(left, left.size()))%mod * rec(right, right.size()))%mod;
        return ans;
    }
public:
    int numOfWays(vector<int>& nums) {
        if(!done){
            int m = mod; 
            InverseofNumber(m); 
            InverseofFactorial(m); 
            factorial(m); 
            done = true;
        }
        return (rec(nums, nums.size()) - 1 + mod)%mod;    
    }
};