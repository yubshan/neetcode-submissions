class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> memory;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
       memory[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(memory.find(key) == memory.end()) return "";

        const auto& history = memory[key];
        int l = 0 , r = history.size()-1;
        string res = "";


        while(l <= r){
            int mid = l + (r-l)/2;
            pair<int, string> value = history[mid];
            if(value.first <= timestamp){
                res = history[mid].second;
                l = mid + 1;
            }else{
                r = mid  - 1;
            }
        }
        
       return res;
    }
};
