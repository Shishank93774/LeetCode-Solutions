class SnapshotArray {
    vector<vector<int> > lastModified;
    int curSnap;
    map<int, int> modifications;
    vector<map<int, int> > snaps;
public:
    SnapshotArray(int length) {
        lastModified.assign(length, {});
        curSnap = 0;
    }
    
    void set(int idx, int val) {
        modifications[idx] = val;
        if(lastModified[idx].size() == 0 or lastModified[idx].back() != curSnap)
            lastModified[idx].push_back(curSnap);
    }
    
    int snap() {
        snaps.push_back(modifications); modifications.clear();
        return curSnap++;
    }
    
    int get(int idx, int snap_id) {
        auto &vec = lastModified[idx];
        auto it = upper_bound(vec.begin(), vec.end(), snap_id);
        if(it == vec.begin()) return 0; // Wasn't modified
        it = prev(it); // last modification was done at this snap
        int lstSnap = *it;
        return snaps[lstSnap][idx];        
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */