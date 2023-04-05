class Solution {
    bool isprime(int n) { 
    if (n <= 1) return false; 
    if (n <= 3) return true; 
    if (n % 2 == 0 || n % 3 == 0) return false; 
    for (int i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i+2) == 0) return false; 
    return true; 
} 
public:
    bool primeSubOperation(vector<int>& arr) {
        int n = arr.size();
        vector<int> primes;
        primes.push_back(0);
        for(int i = 2; i<=1005; i++) if(isprime(i)) primes.push_back(i);
        int f = -12312;
        for(int i = 0; i<n; i++){
            bool chk = false;
            for(int j = primes.size() - 1; j>=0; j--){
                if(arr[i] > primes[j] and (arr[i] - primes[j]) > f){
                    f = arr[i] - primes[j];
                    chk = true;
                    break;
                }
            }
            if(!chk) return false;
        }
        return true;
    }
};