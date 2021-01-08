#include "../include.h"

class UndergroundSystem {
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        travel_record[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t) {
        auto travel_itr = travel_record.find(id); // retrieve checkIn record
        string station_key = travel_itr->second.first + "," + stationName;
        auto station_itr = station_time.find(station_key);
        int travel_time = t - travel_itr->second.second;
        if (station_itr != station_time.end()) {
            station_itr->second.first += travel_time;
            station_itr->second.second++;
        } else {
            station_time[station_key] = make_pair(travel_time, 1);
        }
    }

    double getAverageTime(string startStation, string endStation) {
        auto itr = station_time.find(startStation + "," + endStation);
        return double(itr->second.first) / double(itr->second.second);
    }
private:
    /* travel record that uses id and pair<stationName, time>> as key, val*/
    unordered_map<int, pair<string, int>> travel_record;

    /* travel time that stores "startStation,endStation" and pair<totalTime, count>
     * as key, val pair. Here we use "," as delimiter between start and end station */
    unordered_map<string, pair<int, int>> station_time;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
void test1() {
    UndergroundSystem *obj = new UndergroundSystem();
    obj->checkIn(45, "Leyton", 3);
    obj->checkIn(32, "Paradise", 8);
    obj->checkIn(27, "Leyton", 10);
    obj->checkOut(45, "Waterloo", 15);
    obj->checkOut(27, "Waterloo", 20);
    obj->checkOut(32, "Cambridge", 22);
    assert(obj->getAverageTime("Paradise", "Cambridge") == 14.00000);
    assert(obj->getAverageTime("Leyton", "Waterloo") == 11.00000);
    obj->checkIn(10, "Leyton", 24);
    assert(obj->getAverageTime("Leyton", "Waterloo") == 11.00000);
    obj->checkOut(10, "Waterloo", 38);
    assert(obj->getAverageTime("Leyton", "Waterloo") == 12.00000);
}

void test2() {
    UndergroundSystem *obj = new UndergroundSystem();
    obj->checkIn(10, "Leyton", 3);
    obj->checkOut(10, "Paradise", 8);
    assert(obj->getAverageTime("Leyton", "Paradise") == 5.00000);
    obj->checkIn(5, "Leyton", 10);
    obj->checkOut(5, "Paradise", 16);
    assert(obj->getAverageTime("Leyton", "Paradise") == 5.50000);
    obj->checkIn(2, "Leyton", 21);
    obj->checkOut(2, "Paradise", 30);
    cout << obj->getAverageTime("Leyton", "Paradise") << endl;
    assert(obj->getAverageTime("Leyton", "Paradise") == 6.66667);
}

int main() {
    test1();
    test2();
    cout << "Successful\n";
    return 0;
}
