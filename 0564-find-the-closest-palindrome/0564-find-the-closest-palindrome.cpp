#define ll long long
bool all9s(const vector<int> &arr){
    for(int x: arr) if(x != 9) return false;
    return true;
}

void nextPalindromeUtil(vector<int> &arr){
    int n = arr.size();
    int mid = n/2;
    int i = mid - 1;
    int j = (n&1)?mid+1:mid;
    
    bool leftSmaller = false;
    
    while(i>=0 and arr[i] == arr[j]) i--, j++;
    
    if(i<0 or arr[i] < arr[j]) leftSmaller = true;
    
    while(i>=0)
        arr[j++] = arr[i--];
    
    if(leftSmaller){
        int c = 1;
        i = mid - 1;
        j = mid;
        
        if(n&1){
            arr[mid] += c;
            c = arr[mid]/10;
            arr[mid] %= 10;
            j++;
        }
        
        while(i>=0){
            arr[i] += c;
            c = arr[i]/10;
            arr[i] %= 10;
            arr[j++] = arr[i--];
        }
    }
}

void nextPalindrome(vector<int> &arr){
    if(all9s(arr)){
        for(int &x: arr) x = 0;
        arr.push_back(1);
        arr[0] = 1;
    }else{
        nextPalindromeUtil(arr);
    }
}

ll helper(const string &str){
    vector<int> nums;
    for(char c: str) nums.push_back(c-'0');
    
    nextPalindrome(nums);
    
    ll ans = 0;
    for(int x: nums){
        ans = ans*10 + x;
    }
    return ans;
}

class Solution {
public:
    string nearestPalindromic(const string &str) {
        ll num = stoll(str);
        if(num<=10) return to_string(num-1);
        
        ll upper = helper(str);
        
        ll l = 0, r = num - 1;
        
        while(l<=r){
            ll mid = l + (r - l)/2;
            
            ll fx = helper(to_string(mid));
            
            if(fx < num)
                l = mid + 1;
            else r = mid - 1;
        }
        ll lower = helper(to_string(l-1));
        
        if(abs(lower - num) <= abs(upper - num)) return to_string(lower);
        return to_string(upper);
        
    }
};