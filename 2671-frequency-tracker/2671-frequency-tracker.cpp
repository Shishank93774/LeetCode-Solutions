class FrequencyTracker {
    unordered_map<int, int> mp;
    unordered_map<int, int> freqs;
public:
    void add(int number) {          
        int x = mp[number];
        mp[number]++;
        freqs[x]--;
        freqs[mp[number]]++;
    }
    
    void deleteOne(int number) {
        if(mp.find(number) != mp.end()){
            int x = mp[number];
            freqs[x]--;
            if(freqs[x] == 0) freqs.erase(x);
            mp[number]--;
            if(mp[number] == 0){
                mp.erase(number);
            }else{
                x = mp[number];
                freqs[x]++;
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return (freqs[frequency] > 0);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */