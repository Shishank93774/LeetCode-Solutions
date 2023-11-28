const int mod = 1e9+7;
class Solution {
public:
    int numberOfWays(const string &corridor) {
        int cntS = count(corridor.begin(), corridor.end(), 'S'), n = corridor.size();
        if(cntS == 0 or cntS%2) return 0;
        long long ans = 1;
        int i = 0, j = n-1;
        while(i<j and corridor[i] == 'P') i++;
        while(i<j and corridor[j] == 'P') j--;
        
        int cntSeats = 0;
        while(i<j){
            if(corridor[i] == 'S') cntSeats++;
            int k = i+1;
            if(cntSeats == 2){
                int cntPlants = 0;
                while(k<j and corridor[k] == 'P'){
                    cntPlants++, k++;
                }
                ans *= (cntPlants+1);
                ans %= mod;
                cntSeats = 0;
            }
            i = k;
        }
        
        
        return ans;
    }
};