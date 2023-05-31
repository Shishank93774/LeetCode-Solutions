class UndergroundSystem {
    unordered_map<int, pair<int, string> > personCheckIn;
    unordered_map<string, pair<int, int> > outStatus;
public:
    void checkIn(int id, string stationName, int t) { personCheckIn[id] = {t, stationName}; }
    
    void checkOut(int id, string stationName, int t) {
        auto pr = personCheckIn[id];
        personCheckIn.erase(id);
        int checkInTime = pr.first; 
        string checkInStation = pr.second;
        int timeTravelled = t - checkInTime;
        string journey = stationName + "$" + checkInStation;
        if(outStatus.find(journey) != outStatus.end()){
            auto &pr2 = outStatus[journey];
            pr2.first += timeTravelled;
            pr2.second++;
        }else{
            outStatus[journey] = {timeTravelled, 1};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string journey = endStation + "$" + startStation;
        auto pr = outStatus[journey];
        return 1.0*pr.first/pr.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */