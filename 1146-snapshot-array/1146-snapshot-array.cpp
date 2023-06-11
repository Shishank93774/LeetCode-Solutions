class SnapshotArray {
    vector<vector<int> > lastModified; // stores when was this index last modified?
    int curSnap; // cur snap version
    map<int, int> modifications; // what are the modifications (extra changes) done at this snap?
    vector<map<int, int> > snaps; // snapshot's history
public:
    SnapshotArray(int length) {
        lastModified.assign(length, {}); // all indexes weren't modified, hence empty array{} for each one.
        curSnap = 0;
    }
    
    void set(int idx, int val) {
        modifications[idx] = val; // modify value at index idx
        if(lastModified[idx].size() == 0 or lastModified[idx].back() != curSnap) // to store distinct snap values for a particular index.
            lastModified[idx].push_back(curSnap); // adds this snap version to modification history of idx.
    }
    
    int snap() {
        snaps.push_back(modifications);  // add this modification history to our snapshot's history
		modifications.clear(); // clear modification history for next snap.
        return curSnap++;
    }
    
    int get(int idx, int snap_id) {
        auto &vec = lastModified[idx]; // getting modification history of idx
        auto it = upper_bound(vec.begin(), vec.end(), snap_id); // searching for correct modification history of idx
        if(it == vec.begin()) return 0; // Wasn't modified
        it = prev(it); 
        int lstSnap = *it; // last modification was done at this snap
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