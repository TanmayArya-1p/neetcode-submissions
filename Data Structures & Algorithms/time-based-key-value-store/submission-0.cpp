struct Entry {
    string value;
    int timestamp;

    Entry(string value, int timestamp) : value(value) , timestamp(timestamp) {};

};


class TimeMap {
public:

    unordered_map<string, vector<Entry>> index; 



    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        index[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        if (index.find(key) == index.end()) {
            return "";
        }

        auto it = lower_bound(index[key].begin(),index[key].end(), timestamp,  [&](const Entry& a, int val){return (a.timestamp < val);});
        if(it == index[key].end()) it--;
        else if(it == index[key].begin() && it->timestamp != timestamp) return "";
        else if(it->timestamp > timestamp) it--;


        return it->value;
    }
};
