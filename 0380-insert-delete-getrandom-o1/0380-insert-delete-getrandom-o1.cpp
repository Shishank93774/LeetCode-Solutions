#pragma GCC optimize (-O3, -flto, -ffast-math, -march=native, -mtune=native)
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int getRandomNumber(int l, int r){
   uniform_int_distribution<int> dist(l, r);
   return dist(rnd);
}

class RandomizedSet {
    unordered_map<int, int> mp;
    vector<int> vals;
public:
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        mp[val] = vals.size();
        vals.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int lstval = vals.back();
        int curIdx = mp[val];
        
        mp[lstval] = curIdx;
        vals[curIdx] = lstval;
        
        mp.erase(val);
        vals.pop_back();
        return true;
    }
    
    int getRandom() {
        return vals[getRandomNumber(0, (int)vals.size()-1)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */